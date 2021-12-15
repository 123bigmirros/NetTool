#include "../type/init_variety.h"
#include <pcap.h>

void init(){
    get_self_ip();
    device = pcap_open_live(device_info->name,65535,1,0,errBuf);
}

void get_self_ip(){
    bpf_u_int32  net_ip; 
    bpf_u_int32  net_mask;
    pcap_lookupnet(device_info->name,&net_ip,&net_mask,errBuf);
    for(int i = 24;i>=0;i-=8){
        self_ipv4_addr[3-(i/8)] = (net_ip>>i)&0xff;
    }
}


