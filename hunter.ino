#include <Arduino.h>
//#include "LowPower.h"
//#define USE_SERIAL
#include "CC1101.h"
#include "hunter_data.h"

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

//////////////////////////////////////////////////////

void cc_send_data(uint8_t *le_data, int loops);

////////////////////////////////////////////////////////

void setup()
{
#ifdef USE_SERIAL
  Serial.begin(9600);
#endif
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

  cc_setup();
}

void loop()
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
    hunter_data_clear();
    hunter_data_add_bits(0x0F, 5);
    hunter_data_add_bits(action, 8);
    uint8_t *tx_buf = hunter_data_get_buffer();

#ifdef USE_SERIAL
    char out_text[8] = {0};
    for (int i = 0; i < SIZEOF_HUNTER_DATA_BUFFER; i++)
    {
      sprintf(out_text, "0x%02X ", tx_buf[i]);
      Serial.print(out_text);
    }
    Serial.print("\n");
#else
    digitalWrite(LED_ACTIVITY, HIGH);
#endif

    cc_send_data(tx_buf, 16);
  }
}

/////////////////////////////////////////////

CC1101 cc1101;

#define LEDOUTPUT 7

void blinker()
{
  static int i = 0;
  digitalWrite(LEDOUTPUT, i ? HIGH : LOW);
  i = !i;
}

void cc_setup()
{
#ifdef USE_SERIAL
  Serial.begin(9600);
  Serial.println("Starting CC1101...");
#endif
  // blink once to signal the setup
  blinker();
#ifdef USE_SERIAL
  Serial.println("Initialize and set registers.");
#endif
  cc1101.init();
#ifdef USE_SERIAL
  Serial.println("Setting PA_TABLE.");
#endif
  //config2(); // set PA Table here
#if 0
  uint8_t syncWord[] = {0x55, 0x55};
  cc1101.setSyncWord(syncWord, false);
  cc1101.disableAddressCheck();
#endif
  delay(1000);
#ifdef USE_SERIAL
  Serial.print("CC1101_PARTNUM ");
  Serial.println(cc1101.readReg(CC1101_PARTNUM, CC1101_STATUS_REGISTER));
  Serial.print("CC1101_VERSION ");
  Serial.println(cc1101.readReg(CC1101_VERSION, CC1101_STATUS_REGISTER));
  Serial.print("CC1101_MARCSTATE ");
  Serial.println(cc1101.readReg(CC1101_MARCSTATE, CC1101_STATUS_REGISTER) & 0x1f);

  Serial.println("device initialized");
#endif
}

void cc_send_data(uint8_t *le_data, int loops)
{
  uint8_t data[SIZEOF_HUNTER_DATA_BUFFER];

  memcpy(data, le_data, sizeof(data));

  for (int i = 0; i < loops; i++)
  {
    blinker();
    if (!cc1101.sendData(data, SIZEOF_HUNTER_DATA_BUFFER))
    {
#ifdef USE_SERIAL
      Serial.println("sent failed :(");
#endif
    }
    delay(10);
  }
}

