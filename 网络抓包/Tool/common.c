#include "../type/init_variety.h"
void get_address(struct ADDRESS* addr,u_char* to_mac,u_char* to_ip){
    for(int i = 0;i < MAC_ADDR_LEN;i++) addr->mac_addr_from[i] = self_mac_addr[i],addr->mac_addr_to[i] = to_mac[i];
    for(int i = 0;i < IPV4_ADDR_LEN;i++) addr->ip_addr_from[i] = self_ipv4_addr[i],addr->ip_addr_to[i] = to_ip[i];
}