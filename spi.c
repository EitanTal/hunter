#include "spi.h"
#include "io.h"
#include "main.h"

#include "stm8l10x.h"

#define SS_CONTROL_SOFTWARE 1
#define WAIT_MISO  1

// Wait until SPI operation is terminated
static void wait_Spi(void)
{
  // ! Replace arduino
  //while(!(SPSR & _BV(SPIF))) {;}
  while (!SPI_GetFlagStatus(SPI_FLAG_BSY)) {;}
}

/**
 * init
 * 
 * SPI initialization
 */
void spi_init(void)
{
  pinMode(SPI_SS,   OUTPUT);
  pinMode(SPI_MOSI, OUTPUT);
  pinMode(SPI_SCK,  OUTPUT);
  pinMode(SPI_MISO, INPUT);
#if 0
  digitalWrite(SPI_SS, 0);
  digitalWrite(SPI_MOSI, 0);
  digitalWrite(SPI_SCK, 0);
#endif

#if SS_CONTROL_SOFTWARE
  //digitalWrite(SPI_SS, 1); // no need. it's the default
#endif

  SPI_Init(SPI_FirstBit_MSB, SPI_BaudRatePrescaler_4, SPI_Mode_Master,
           SPI_CPOL_Low,   // ! unsure
           SPI_CPHA_1Edge, // ! unsure
           SPI_Direction_2Lines_FullDuplex, SPI_NSS_Soft);

  SPI_Cmd(ENABLE);
}

/**
 * spi_send: Exchange a single byte on SPI. Send one byte, receive one byte.
 */
uint8_t spi_send(uint8_t value)
{
  SPI_SendData(value);
  //wait_Spi();   // Wait until SPI operation is terminated
  return SPI_ReceiveData();
}

// Select (SPI) CC1101
void cc1101_Select(void)
{
  //bitClear(PORT_SPI_SS, BIT_SPI_SS);
#if SS_CONTROL_SOFTWARE // ! unsure if this is needed
  digitalWrite(SPI_SS, 0);
#endif
}

// Deselect (SPI) CC1101
void cc1101_Deselect(void)
{
  //bitSet(PORT_SPI_SS, BIT_SPI_SS);
#if SS_CONTROL_SOFTWARE // ! unsure if this is needed
  digitalWrite(SPI_SS, 1);
#endif
}

// Wait until SPI MISO line goes low
void wait_Miso(void)
{
  //while (bitRead(PORT_SPI_MISO, BIT_SPI_MISO));
#if WAIT_MISO // ! unsure if this is needed
  int val = 0;
	do {
		val = digitalRead(SPI_MISO);
  } while (val != 0);
#endif
}
