#include "spi.h"
#include <Arduino.h>

/**
 * init
 * 
 * SPI initialization
 */
void spi_init() 
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
  SPCR = _BV(SPE) | _BV(MSTR);
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
  SPDR = value;                          // Transfer byte via SPI
  wait_Spi();                            // Wait until SPI operation is terminated

  return SPDR;
}

