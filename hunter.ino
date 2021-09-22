#include <Arduino.h>
//#include "LowPower.h"
//#define USE_SERIAL
#include "CC1101.h"

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

enum
{
  LIGHT       = 0b00000001,
  FAN_OFF     = 0b00000010,
  FAN_REVERSE = 0b00000100,
  FAN_3       = 0b00001000,
  FAN_2       = 0b00010000,
  FAN_1       = 0b00100000,
};

uint64_t tx_out = 0;
static int tx_bit_offset = 0;

//////////////////////////////////////////////////////

void send_data(uint8_t* le_data, int loops);

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

void my_tx(uint8_t a, int bits)
{
  a = a << 8-bits;
  for (int i = 0; i < bits; i++)
  {
    my_tx_bit(a & 0x80);
    a = a << 1;
  }
}

void my_tx_bit(uint8_t a)
{
  uint64_t tmp = (a ? 0b110 : 0b100);  // ! These are Mirrored.
  tmp = tmp << tx_bit_offset;
  tx_bit_offset += 3;
  tx_out |= tmp;
}

uint8_t mirror(uint8_t a)
{
  uint8_t result = 0;
  for (int i = 0; i < 8; i++)
  {
    result |= (!!(a & 0x80)) << i;
    a = a << 1;
  }
  return result;
}

void loop() 
{
  tx_out = 0;
  tx_bit_offset = 0;
  int action = 0;

  digitalWrite(LED_ACTIVITY, LOW);
  delay(10); // ! replace with low-power

  if (digitalRead(BUTTON_1) == LOW) action = LIGHT; 
  if (digitalRead(BUTTON_2) == LOW) action = FAN_OFF;
  if (digitalRead(BUTTON_3) == LOW) action = FAN_REVERSE;
  if (digitalRead(BUTTON_4) == LOW) action = FAN_3;
  if (digitalRead(BUTTON_5) == LOW) action = FAN_2;
  if (digitalRead(BUTTON_6) == LOW) action = FAN_1;

  if (action != 0)
  {
    my_tx(0x0F, 5);
    my_tx(action, 8);

    char out_text[8] = {0};

    uint8_t * tx_buf = (uint8_t*)&tx_out;
    for(int i = 0; i < 5; i++)
    {
      tx_buf[i] = mirror(tx_buf[i]);
    }
#ifdef USE_SERIAL
    for(int i = 0; i < 5; i++)
    {
      sprintf(out_text, "0x%02X ", tx_buf[i]);
      Serial.print(out_text);
    }
    Serial.print("\n");
#else
    digitalWrite(LED_ACTIVITY, HIGH);
#endif
    //delay(200); // ! replace with a loop to transmit the code for long enough time.
    send_data(tx_buf, 100);
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
    Serial.begin(9600);
    Serial.println("Starting CC1101...");

    // blink once to signal the setup
    blinker();

    Serial.println("Initialize and set registers.");

    cc1101.init();

    Serial.println("Setting PA_TABLE.");
    config2();

    uint8_t syncWord[] = {0x55, 0x55};
    cc1101.setSyncWord(syncWord, false);
    cc1101.setCarrierFreq(CFREQ_302);
    cc1101.disableAddressCheck();

    delay(1000);

    Serial.print("CC1101_PARTNUM ");
    Serial.println(cc1101.readReg(CC1101_PARTNUM, CC1101_STATUS_REGISTER));
    Serial.print("CC1101_VERSION ");
    Serial.println(cc1101.readReg(CC1101_VERSION, CC1101_STATUS_REGISTER));
    Serial.print("CC1101_MARCSTATE ");
    Serial.println(cc1101.readReg(CC1101_MARCSTATE, CC1101_STATUS_REGISTER) & 0x1f);

    Serial.println("device initialized");
}

void send_data(uint8_t* le_data, int loops)
{
    CCPACKET data;

    data.length = 5;
    uint8_t known_good_data[] = {0b00101101, 0b10110110, 0b01001011, 0b00100100, 0b10010010};

    memset(data.data, 0, sizeof(data.data));
    memcpy(data.data, known_good_data, sizeof(data.length));

    for (int i = 0; i < loops; i++)
    {
      blinker();
      if (!cc1101.sendData(data))
      {
          Serial.println("sent failed :(");
      }
      delay(10);
    }
}

void config2()
{
    enum
    {
        PA_POWER_MINUS_0  = 0x51,
        PA_POWER_MINUS_15 = 0x1D,
        PA_POWER_MINUS_30 = 0x03,
        PA_POWER_ORIGINAL = 0xC0,
    };
    uint8_t PA_TABLE[] = {0x00, PA_POWER_MINUS_0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    cc1101.writeBurstReg(CC1101_PATABLE, PA_TABLE, 8);
}
