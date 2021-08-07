
// the sensor communicates using SPI, so include the library:
#include <SPI.h>
#include <stdint.h>

// pins used for the connection with the sensor
// the other you need are controlled by the SPI library):
const int dataReadyPin = 6;
const int chipSelectPin = 7;

int led = 13;

void setup() {
//  Serial.begin(9600);

  // start the SPI library:
//  SPI.begin();
  
//  SPI.setClockDivider(SPI_CLOCK_DIV128);

  // initalize the  data ready and chip select pins:
//  pinMode(dataReadyPin, INPUT);
//  pinMode(chipSelectPin, OUTPUT);
  pinMode(led, OUTPUT);

  // give the sensor time to set up:
  delay(100);
}
#if 0
void my_tx(int a)
{
  static const uint8_t triplet_lo[16] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
  static const uint8_t triplet_hi[16]  = {0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

  if (a == 0)
  {
    for (int i = 0; i < sizeof(triplet_lo); i++)
      SPI.transfer(triplet_lo[i]);
  }
  else
  {
    for (int i = 0; i < sizeof(triplet_hi); i++)
      SPI.transfer(triplet_hi[i]);
  }
}
#else

void my_tx(uint8_t a, int bits)
{
  a = a << 8-bits;
  for (int i = 0; i < bits; i++)
  {
    my_tx_bit(a & 0x80);
    a = a << 1;
  }
}

#if 1
#define MY_HIGH LOW
#define MY_LOW HIGH
#else
#define MY_HIGH HIGH
#define MY_LOW LOW
#endif

void my_tx_bit(int a)
{
  enum { UNIT_LEN_US = 323 };
//  enum { UNIT_LEN_US = 1000 };

  digitalWrite(led, MY_LOW);
  if (a == 0)
  {
    delayMicroseconds(UNIT_LEN_US);
    delayMicroseconds(UNIT_LEN_US);
    digitalWrite(led, MY_HIGH);
    delayMicroseconds(UNIT_LEN_US);
  }
  else
  {
    delayMicroseconds(UNIT_LEN_US);
    digitalWrite(led, MY_HIGH);
    delayMicroseconds(UNIT_LEN_US);
    delayMicroseconds(UNIT_LEN_US);
  }
  digitalWrite(led, MY_LOW);
}
#endif

void loop() 
{
    my_tx(0x0F, 5);
    my_tx(0x20, 8);
    
    delay(10);
    
   Serial.print("Temp[C]=\n");
}


