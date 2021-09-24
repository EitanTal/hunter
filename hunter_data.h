#pragma once

#include <stdint.h>

enum
{
  DATA_LIGHT       = 0b00000001,
  DATA_FAN_OFF     = 0b00000010,
  DATA_FAN_REVERSE = 0b00000100,
  DATA_FAN_3       = 0b00001000,
  DATA_FAN_2       = 0b00010000,
  DATA_FAN_1       = 0b00100000,
};

enum
{
  SIZEOF_HUNTER_DATA_BUFFER = 5
};

void hunter_data_clear();

void hunter_data_add_bits(uint8_t a, int bits);

uint8_t* hunter_data_get_buffer();
