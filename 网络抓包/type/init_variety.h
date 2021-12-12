#include "defn.h"
#include "protocol.h"
#include "variety.h"
#ifndef INIT_VARIETY
#define INIT_VARIETY
enum P_TYPE{MAC,ARP,IP};

void (*p_func[])(u_char *bytes) = {ALS_ARP,ALS_IP};
struct data* (*build_func[])(struct ADDRESS* addr,struct DATA* data) = {build_arp};

enum P_TYPE p_head_build_order[][10] = {{ARP,MAC,-1}};
#define unit_8_to_16(x,y) (((uint)x<<8)|(uint)y)
#define unit_8_to_32(x,y,z,k) (((uint)x<<24)|((uint)y<<16)|((uint)z<<8)|(uint)k)
#define unit_8_to_pre4(x) ((u_char)x>>4)
#define unit_8_to_suf4(x) ((u_char)x&0x0f)
#endif