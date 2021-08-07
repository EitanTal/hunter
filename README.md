# Intro

This is a recreation of an Old-school Hunter fan remote

## Digital signals

Every packet is as follows:

   [`address`][`opcode`]

address is 5 bits long, opcode is 8 bits long. Address used = 0b01111

### Packets & Opcodes

* light:    0x0F (01111) 0x1 (00000001)
* fan off:  0x0F (01111) 0x2 (00000010)
* fan rev:                   (00000100)
* fan 3:                     (00001000)
* fan 2:                     (00010000)
* fan 1:    0x0F             (00100000)

## Pulse layout

short pulse: (0)

      _
    __

long pulse: (1)

     __
    _

## Pulse timing

length of each character: 328.4us (0.3284ms)

every 1 bit = 8us.
41 bits = one unit.
~16 bytes per triplet.

## Radio notes

significant wide band activity in:
304MHz

some additional activity in:
609MHz
914MHz
1218MHz
