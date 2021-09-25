#include "spi.h"
#include "io.h"
#include "main.h"

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
  digitalWrite(SPI_SS, HIGH);
  
  // Configure SPI pins
  pinMode(SPI_SS, OUTPUT);
  pinMode(SPI_MOSI, OUTPUT);
  pinMode(SPI_MISO, INPUT);
  pinMode(SPI_SCK, OUTPUT);

  digitalWrite(SPI_SCK, HIGH);
  digitalWrite(SPI_MOSI, LOW);

  // SPI speed = clk/4
  //SPCR = _BV(SPE) | _BV(MSTR);   // ! Replace arduino
}

/**
 * spi_send
 * 
 * Send byte via SPI
 * 
 * 'value'	Value to be sent
 * 
 * Return:
 * 	Response received from SPI slave
 */
uint8_t spi_send(uint8_t value) 
{
  int SPDR; // ! Arduino
  SPDR = value;                          // Transfer byte via SPI
  wait_Spi();                            // Wait until SPI operation is terminated

  return SPDR;
}

// Select (SPI) CC1101
void cc1101_Select(void)
{
  bitClear(PORT_SPI_SS, BIT_SPI_SS);
}

// Deselect (SPI) CC1101
void cc1101_Deselect(void)
{
  bitSet(PORT_SPI_SS, BIT_SPI_SS);
}

// Wait until SPI MISO line goes low
void wait_Miso(void)
{
  while(bitRead(PORT_SPI_MISO, BIT_SPI_MISO));
}
