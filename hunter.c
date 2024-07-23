#include "CC1101.h"
#include "hunter_data.h"
#include "main.h"
#include "io.h"
#include "time.h"
#include "stm8l10x_clk.h"
#include "stm8l10x_exti.h"

enum
{
  BUTTON_LIGHT = PIN_Z0,
  BUTTON_LIGHT_UP = PIN_Z1,
  BUTTON_LIGHT_DOWN = PIN_A0,
  BUTTON_FAN = 3,
  BUTTON_FAN_UP = 5,
  BUTTON_FAN_DOWN = 9
};

enum
{
	MY_LED_11 = 2, // Arduino D2 equivalent
	MY_LED_2  = 6  // Arduino D6 equivalent
};

enum
{
  COMMAND_ERROR,
  COMMAND_OK
};

#define PULL_UP_RESISTOR_PRESENT

////////////////////////////////////////////////////////


static void WFI(void)
{
  AWU_IdleModeEnable();
	//__asm("WFI");
  __asm("HALT");
}

static void ENABLE_INTERRUPTS(void)
{
	__asm("RIM");
}

void setup(void)
{
  CLK_PeripheralClockConfig(CLK_Peripheral_SPI, ENABLE);
  
	pinMode(MY_LED_11, OUTPUT);
	pinMode(MY_LED_2, OUTPUT);

  pinMode(BUTTON_LIGHT, INPUT_PULLUP);
  pinMode(BUTTON_LIGHT_UP, INPUT_PULLUP);
  pinMode(BUTTON_LIGHT_DOWN, INPUT_PULLUP);
  pinMode(BUTTON_FAN, INPUT_PULLUP);
  pinMode(BUTTON_FAN_UP, INPUT_PULLUP);
  pinMode(BUTTON_FAN_DOWN, INPUT_PULLUP);

  EXTI_SetPortSensitivity(EXTI_Port_B, EXTI_Trigger_Falling); // B2
  EXTI_SetPinSensitivity(EXTI_Pin_0, EXTI_Trigger_Falling);   // B0
  EXTI_SetPinSensitivity(EXTI_Pin_1, EXTI_Trigger_Falling);   // C1
  EXTI_SetPinSensitivity(EXTI_Pin_2, EXTI_Trigger_Falling);   // C2
  EXTI_SetPinSensitivity(EXTI_Pin_3, EXTI_Trigger_Falling);   // B3
  EXTI_SetPinSensitivity(EXTI_Pin_4, EXTI_Trigger_Falling);   // C4

  //cc1101_init();
  AWU_Init(AWU_Timebase_1ms);
  
  delay(1000);

  ENABLE_INTERRUPTS();
}

void send_action(int action, int ok)
{
  uint8_t *tx_buf;
  int i;
	int j;
  //int loop_count = (action == DATA_LIGHT) ? 5 : 16; // Light button requires less repetitions, or else it is counted as a double click.
  int loop_count = 5;
  int loop_count2 = (action == DATA_LIGHT) ? 1 : 3; // Light button requires less repetitions, or else it is counted as a double click.
  hunter_data_clear();
  hunter_data_add_bits(0x0F, 5);
  hunter_data_add_bits(action, 8);
  tx_buf = hunter_data_get_buffer();
	
  for (j = 0; j < loop_count2; j++)
  {
	cc1101_init();

  for (i = 0; i < loop_count; i++)
  {
    if (ok == COMMAND_OK)
    {
      digitalWrite(MY_LED_11, ((i%2) ? HIGH : LOW));
      digitalWrite(MY_LED_2, ((i%2) ? HIGH : LOW));
    }
    else
    {
      digitalWrite(MY_LED_11, (((i/4)%2) ? HIGH : LOW));
      digitalWrite(MY_LED_2, (((i/4)%2) ? LOW : HIGH));
    }
    cc1101_sendData(tx_buf, SIZEOF_HUNTER_DATA_BUFFER);
    delay(10);
  }
  }
	
	cc1101_off();
}

int speed2action(int8_t new_speed)
{
  switch (new_speed)
  {
    case 1:    return DATA_FAN_3;
    case 2:    return DATA_FAN_2;
    case 3:    return DATA_FAN_1;
  }
  return DATA_FAN_OFF;
}

void loop(void)
{
  static int8_t current_fan_speed = 0;
  static int8_t saved_fan_speed = 3; // Default to highest speed.

  digitalWrite(MY_LED_11, LOW);
  digitalWrite(MY_LED_2, LOW);
  delay(100);
  cc1101_off(); // turn off again before going to sleep, just in case
	WFI();

  if (digitalRead(BUTTON_LIGHT) == LOW)
  {
    send_action(DATA_LIGHT, COMMAND_OK);
  }
#if 0 // No support for light-up / light-down
  if (digitalRead(BUTTON_LIGHT_UP) == LOW) action = DATA_FAN_OFF;
  if (digitalRead(BUTTON_LIGHT_DOWN) == LOW) action = DATA_FAN_REVERSE;
#endif

#ifdef PULL_UP_RESISTOR_PRESENT
  if (digitalRead(BUTTON_FAN) == LOW)
  {
    if (current_fan_speed == 0) 
    {
      // If the fan is not running, recall the saved fan speed.
      current_fan_speed = saved_fan_speed;
    }
    else
    {
      // If the fan is running, store its current speed and stop the fan.
      saved_fan_speed = current_fan_speed;
      current_fan_speed = 0;
    }
    send_action(speed2action(current_fan_speed), COMMAND_OK);
  }
#else
#warning "Special build: No pull-up resistor"
#endif
  if ((digitalRead(BUTTON_FAN_UP) == LOW) && (digitalRead(BUTTON_FAN_DOWN) == LOW))
  {
    send_action(DATA_FAN_REVERSE, COMMAND_OK);
  }
  else
  {
    if (digitalRead(BUTTON_FAN_UP) == LOW)
    {
      current_fan_speed++;
      if (current_fan_speed > 3) 
      {
        current_fan_speed = 3;
        send_action(speed2action(current_fan_speed), COMMAND_ERROR);
      }
      else
      {
        send_action(speed2action(current_fan_speed), COMMAND_OK);
      }
    }
    if (digitalRead(BUTTON_FAN_DOWN) == LOW)
    {
      current_fan_speed--;
      if (current_fan_speed < 0)
      {
        current_fan_speed = 0;
        send_action(speed2action(current_fan_speed), COMMAND_ERROR);
      }
      else
      {
        send_action(speed2action(current_fan_speed), COMMAND_OK);
      }
    } 
  }
}
