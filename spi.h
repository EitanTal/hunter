#pragma once

/**
 * SPI pins
 */
#define SPI_SS   10     // PB2 = SPI_SS
#define SPI_MOSI 11     // PB3 = MOSI
#define SPI_MISO 12     // PB4 = MISO
#define SPI_SCK  13     // PB5 = SCK
#define GDO0	 2        // PD2 = INT0

#define PORT_SPI_MISO  PINB
#define BIT_SPI_MISO  4

#define PORT_SPI_SS  PORTB
#define BIT_SPI_SS   2

#define PORT_GDO0  PIND
#define BIT_GDO0  2

void spi_init(void);

uint8_t spi_send(uint8_t value);

void cc1101_Select(void);

void cc1101_Deselect(void);

void wait_Miso(void);
