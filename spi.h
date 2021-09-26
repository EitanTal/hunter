#pragma once
#include <stdint.h>

void spi_init(void);

uint8_t spi_send(uint8_t value);

void cc1101_Select(void);

void cc1101_Deselect(void);

void wait_Miso(void);
