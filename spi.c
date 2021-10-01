#include "spi.h"
#include "io.h"
#include "main.h"

#include "stm8l10x.h"

// Wait until SPI operation is terminated
static void wait_Spi(void)
{
  // ! Replace arduino
  //while(!(SPSR & _BV(SPIF))) {;}
}

/**
 * init
 * 
 * SPI initialization
 */
void spi_init(void)
{
  SPI_Init(SPI_FirstBit_MSB, SPI_BaudRatePrescaler_4, SPI_Mode_Master,
           SPI_CPOL_Low,   // ! unsure
           SPI_CPHA_1Edge, // ! unsure
           SPI_Direction_2Lines_FullDuplex, SPI_NSS_Hard);
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
#if 0 // ! unsure if this is needed
  digitalWrite(SPI_SS, 0);
#endif
}

// Deselect (SPI) CC1101
void cc1101_Deselect(void)
{
  //bitSet(PORT_SPI_SS, BIT_SPI_SS);
#if 0 // ! unsure if this is needed
  digitalWrite(SPI_SS, 1);
#endif
}

// Wait until SPI MISO line goes low
void wait_Miso(void)
{
  //while (bitRead(PORT_SPI_MISO, BIT_SPI_MISO));
#if 0 // ! unsure if this is needed
  while (digitalRead(SPI_MISO));
#endif
}
