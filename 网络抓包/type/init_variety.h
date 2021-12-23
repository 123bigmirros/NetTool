#include "defn.h"
#ifndef INIT_VARIETY
#define INIT_VARIETY

typedef u_char IPv4_ADDR[4];
typedef u_char MAC_ADDR[6];

IPv4_ADDR self_ipv4_addr;//当前设备IP地址
MAC_ADDR self_mac_addr  = {0x28,0x16,0xA8,0x63,0x14,0xAB};//当前设备mac地址
pcap_if_t* device_info;//当前设备基本信息
pcap_t* device;//保存当前开启的设备句柄
char errBuf[PCAP_ERRBUF_SIZE];//保存错误信息


void (*p_analyse[])(u_char *bytes) = {ALS_ARP,ALS_IP};
struct data* (*build_func[])(struct ADDRESS* addr) = {[MAC]=build_mac_head,[IP]=build_ip_head};
void (*setup_type_field[])(void* protol,enum P_TYPE uppper) = {[MAC] = setup_mac_type_field};


#define unit_8_to_16(x,y) (((uint)x<<8)|(uint)y)
#define unit_8_to_32(x,y,z,k) (((uint)x<<24)|((uint)y<<16)|((uint)z<<8)|(uint)k)
#define unit_8_to_pre4(x) ((u_char)x>>4)
#define unit_8_to_suf4(x) ((u_char)x&0x0f)
#define sizeof_2d_array(x) (sizeof(x)/sizeof(*x))
#endif