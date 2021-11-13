#include "CC1101.h"
#include "hunter_data.h"
#include "main.h"
#include "io.h"
#include "time.h"
#include "stm8l10x_clk.h"

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
	MY_LED_2  = 6,  // Arduino D6 equivalent
  LED_ACTIVITY = MY_LED_11
};

////////////////////////////////////////////////////////

void setup(void)
{
  CLK_PeripheralClockConfig(CLK_Peripheral_SPI, ENABLE);

	pinMode(MY_LED_11, OUTPUT);
	pinMode(MY_LED_2, OUTPUT);

  pinMode(BUTTON_1, INPUT_PULLUP);
  pinMode(BUTTON_2, INPUT_PULLUP);
  pinMode(BUTTON_3, INPUT_PULLUP);
  pinMode(BUTTON_4, INPUT_PULLUP);
  pinMode(BUTTON_5, INPUT_PULLUP);
  pinMode(BUTTON_6, INPUT_PULLUP);

  cc1101_init();

  delay(1000);
}

void loop(void)
{
  int action = 0;

  digitalWrite(LED_ACTIVITY, LOW);
  delay(10); // ! replace with low-power

  if (digitalRead(BUTTON_1) == LOW) action = DATA_LIGHT; 
  if (digitalRead(BUTTON_2) == LOW) action = DATA_FAN_OFF;
  if (digitalRead(BUTTON_3) == LOW) action = DATA_FAN_REVERSE;
  //if (digitalRead(BUTTON_4) == LOW) action = DATA_FAN_3;
  if (digitalRead(BUTTON_5) == LOW) action = DATA_FAN_2;
  if (digitalRead(BUTTON_6) == LOW) action = DATA_FAN_1;

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
