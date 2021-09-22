#include <Arduino.h>
#define LED_ACTIVITY 7

uint64_t tx_out = 0;
static int tx_bit_offset = 0;

void setup() 
{
  Serial.begin(9600);

  pinMode(LED_ACTIVITY, OUTPUT);
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
  my_tx(0x0F, 5);
  my_tx(0x20, 8);

  delay(10);
  char out_text[8] = {0};

  uint8_t * tx_buf = (uint8_t*)&tx_out;
  for(int i = 0; i < 5; i++)
  {
    sprintf(out_text, "0x%02X ", mirror(tx_buf[i]));
    Serial.print(out_text);
  }
  Serial.print("\n");
}
