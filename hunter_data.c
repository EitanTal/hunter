#include <stdint.h>

/////////////////////////////////////////////////////////////

uint64_t tx_out = 0;
static int tx_bit_offset = 0;
static bool is_mirrored = false;

static void my_tx_bit(uint8_t a);
static uint8_t mirror(uint8_t a);

/////////////////////////////////////////////////////////////

void hunter_data_clear()
{
  tx_out = 0;
  tx_bit_offset = 0;
  is_mirrored = false;
}

void hunter_data_add_bits(uint8_t a, int bits)
{
  a = a << 8-bits;
  for (int i = 0; i < bits; i++)
  {
    my_tx_bit(a & 0x80);
    a = a << 1;
  }
}

uint8_t* hunter_data_get_buffer()
{
  uint8_t * tx_buf = (uint8_t*)&tx_out;

  if (!is_mirrored)
  {
    for(int i = 0; i < 5; i++)
    {
      tx_buf[i] = mirror(tx_buf[i]);
    }
    is_mirrored = true;
  }

  return tx_buf;
}

/////////////////////////////////////////////////////////////

static void my_tx_bit(uint8_t a)
{
  uint64_t tmp = (a ? 0b110 : 0b100);  // ! These are Mirrored.
  tmp = tmp << tx_bit_offset;
  tx_bit_offset += 3;
  tx_out |= tmp;
}

static uint8_t mirror(uint8_t a)
{
  uint8_t result = 0;
  for (int i = 0; i < 8; i++)
  {
    result |= (!!(a & 0x80)) << i;
    a = a << 1;
  }
  return result;
}
