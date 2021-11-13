#include "CC1101.h"
#include "hunter_data.h"
#include "main.h"
#include "io.h"
#include "time.h"
#include "stm8l10x_clk.h"

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
	MY_LED_2  = 6,  // Arduino D6 equivalent
  LED_ACTIVITY = MY_LED_11
};

////////////////////////////////////////////////////////

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

  cc1101_init();

  delay(1000);
}

void loop(void)
{
  int action = 0;

  digitalWrite(LED_ACTIVITY, LOW);
  delay(10); // ! replace with low-power

  if (digitalRead(BUTTON_LIGHT) == LOW) action = DATA_LIGHT; 
  if (digitalRead(BUTTON_LIGHT_UP) == LOW) action = DATA_FAN_OFF;
  if (digitalRead(BUTTON_LIGHT_DOWN) == LOW) action = DATA_FAN_REVERSE;
  //if (digitalRead(BUTTON_FAN) == LOW) action = DATA_FAN_3;
  if (digitalRead(BUTTON_FAN_UP) == LOW) action = DATA_FAN_2;
  if (digitalRead(BUTTON_FAN_DOWN) == LOW) action = DATA_FAN_1;

  if (action != 0)
  {
		uint8_t *tx_buf;
		int i;
    hunter_data_clear();
    hunter_data_add_bits(0x0F, 5);
    hunter_data_add_bits(action, 8);
    tx_buf = hunter_data_get_buffer();

    digitalWrite(LED_ACTIVITY, HIGH);
    for (i = 0; i < 16; i++)
    {
      digitalWrite(LED_ACTIVITY, ((i%2) ? HIGH : LOW));
      cc1101_sendData(tx_buf, SIZEOF_HUNTER_DATA_BUFFER);
      delay(10);
    }
  }
}
