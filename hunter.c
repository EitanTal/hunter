#include "CC1101.h"
#include "hunter_data.h"
#include "main.h"
#include "io.h"
#include "time.h"

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

////////////////////////////////////////////////////////

void setup(void)
{
  pinMode(LED_ACTIVITY, OUTPUT);
  pinMode(BUTTON_1, INPUT);
  pinMode(BUTTON_2, INPUT);
  pinMode(BUTTON_3, INPUT);
  pinMode(BUTTON_4, INPUT);
  pinMode(BUTTON_5, INPUT);
  pinMode(BUTTON_6, INPUT);
  digitalWrite(BUTTON_1, HIGH);
  digitalWrite(BUTTON_2, HIGH);
  digitalWrite(BUTTON_3, HIGH);
  digitalWrite(BUTTON_4, HIGH);
  digitalWrite(BUTTON_5, HIGH);
  digitalWrite(BUTTON_6, HIGH);

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
  if (digitalRead(BUTTON_4) == LOW) action = DATA_FAN_3;
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
