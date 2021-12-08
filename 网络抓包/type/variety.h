#ifndef VARIETY
#define VARIETY

typedef unsigned int uint;
#define MAC_LEN 6
#define unit_8_to_16(x,y) (((uint)x<<8)|(uint)y)
#define unit_8_to_32(x,y,z,k) (((uint)x<<24)|((uint)y<<16)|((uint)z<<8)|(uint)k)
#define unit_8_to_pre4(x) ((u_char)x>>4)
#define unit_8_to_suf4(x) ((u_char)x&0x0f)

#endif