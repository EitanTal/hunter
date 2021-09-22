def add_bits( data, bits_to_add ):
    tmp_result = ''
    for i in range(bits_to_add):
        tmp_result = ('0' if (data %2==0) else '1') + tmp_result
        data = data >> 1
    result = ''
    for x in tmp_result:
        result = result + ('011' if (x=='1') else '001')
    return result

def break_into_8bits(bitstream):
    result = []
    for i in range(0,len(bitstream),8):
        unpadded = bitstream[i:i+8]
        padded = (unpadded + '00000000')[:8]
        result += ['0b' + padded]
    return '{' + str.join(', ', result) + '}'

a = add_bits(0x0F, 5) # Address
a += add_bits(0x20, 8) # Fan-3 opcode
b = break_into_8bits(a)
print(b)
