#include "CC1101.h"
#include "hunter_data.h"
#include "main.h"
#include "io.h"
#include "time.h"
#include "stm8l10x_clk.h"

#if 0
enum
{
  BUTTON_1 = 4,
  BUTTON_2 = 5,
  BUTTON_3 = 6,
  BUTTON_4 = 8,
  BUTTON_5 = 9,
  BUTTON_6 = PIN_A0,
  LED_ACTIVITY = 7
};
#else
enum
{
  BUTTON_1 = PIN_Z0,
  BUTTON_2 = PIN_Z1,
  BUTTON_3 = PIN_A0,
  BUTTON_4 = 3,
  BUTTON_5 = 5,
  BUTTON_6 = 9
};

enum
{
	MY_LED_11 = 2, // Arduino D2 equivalent
	MY_LED_2  = 6  // Arduino D6 equivalent
};

#endif

////////////////////////////////////////////////////////

void setup(void)
{
#if 1
  CLK_PeripheralClockConfig(CLK_Peripheral_SPI, ENABLE);
#endif

#if 0
  pinMode(LED_ACTIVITY, OUTPUT);
#else
	pinMode(MY_LED_11, OUTPUT);
	pinMode(MY_LED_2, OUTPUT);
#endif
  pinMode(BUTTON_1, INPUT_PULLUP);
  pinMode(BUTTON_2, INPUT_PULLUP);
  pinMode(BUTTON_3, INPUT_PULLUP);
  pinMode(BUTTON_4, INPUT_PULLUP);
  pinMode(BUTTON_5, INPUT_PULLUP);
  pinMode(BUTTON_6, INPUT_PULLUP);
#if 0 // existing code
  digitalWrite(BUTTON_1, HIGH);
  digitalWrite(BUTTON_2, HIGH);
  digitalWrite(BUTTON_3, HIGH);
  digitalWrite(BUTTON_4, HIGH);
  digitalWrite(BUTTON_5, HIGH);
  digitalWrite(BUTTON_6, HIGH);
#endif
  cc1101_init();

  delay(1000);
}

void loop(void)
{
#if 1
  int action = 0;

  #define LED_ACTIVITY  MY_LED_11

  digitalWrite(LED_ACTIVITY, LOW);
  delay(10); // ! replace with low-power

  if (digitalRead(BUTTON_1) == LOW) action = DATA_LIGHT; 
  if (digitalRead(BUTTON_2) == LOW) action = DATA_FAN_OFF;
  if (digitalRead(BUTTON_3) == LOW) action = DATA_FAN_REVERSE;
  //if (digitalRead(BUTTON_4) == LOW) action = DATA_FAN_3;
  if (digitalRead(BUTTON_5) == LOW) action = DATA_FAN_2;
  if (digitalRead(BUTTON_6) == LOW) action = DATA_FAN_1;

  if (action != 0)
	//if (0)
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
#else
  static int i = 0;
  int action = 0;
	digitalWrite(MY_LED_11, i);
	
  if (digitalRead(BUTTON_1) == LOW) action = DATA_LIGHT; 
  if (digitalRead(BUTTON_2) == LOW) action = DATA_FAN_OFF;
  if (digitalRead(BUTTON_3) == LOW) action = DATA_FAN_REVERSE;
  //if (digitalRead(BUTTON_4) == LOW) action = DATA_FAN_3;
  if (digitalRead(BUTTON_5) == LOW) action = DATA_FAN_2;
  if (digitalRead(BUTTON_6) == LOW) action = DATA_FAN_1;

  if (action != 0)
  {
    int j;
    for (j = 0; j < 16; j++)
    {
      digitalWrite(MY_LED_2, ((j%2) ? HIGH : LOW));
      delay(40);
    }
  }

	i = !i;
	delay(100);
#endif
}
