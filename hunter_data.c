#include <stdint.h>
#include <stdbool.h>
#include <string.h>

/////////////////////////////////////////////////////////////

static uint8_t tx_out[5] = {0};
static uint8_t tx_bit_offset = 0;

static void push_symbol(uint8_t a);
static uint8_t mirror(uint8_t a);

/////////////////////////////////////////////////////////////

void hunter_data_clear(void)
{
  //memset(&tx_out, 0, sizeof(tx_out));
	tx_out[0] = 0;
	tx_out[1] = 0;
	tx_out[2] = 0;
	tx_out[3] = 0;
	tx_out[4] = 0;
  tx_bit_offset = 0;
}

void hunter_data_add_bits(uint8_t a, int bits)
{
  int i;
  a = a << 8 - bits;
  for (i = 0; i < bits; i++)
  {
    push_symbol(a & 0x80);
    a = a << 1;
  }
}

uint8_t *hunter_data_get_buffer(void)
{
  int i;
  uint8_t *tx_buf = (uint8_t *)&tx_out;

  return tx_buf;
}

/////////////////////////////////////////////////////////////

static void push_bit(uint8_t bit)
{
  if (bit)
  {
    uint8_t byte_index = tx_bit_offset / 8;
    uint8_t bit_index = tx_bit_offset % 8;
    uint8_t actual_bit_index = 7 - bit_index;
    tx_out[byte_index] |= (1 << actual_bit_index);
  }
  tx_bit_offset++;
}

static void push_symbol(uint8_t a)
{
  push_bit(0);
  push_bit(a ? 1 : 0);
  push_bit(1);
}
