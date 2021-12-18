#include "../type/protocol.h"
#include "../type/init_variety.h"
#include<stdlib.h>

struct DATA* build(int p_level,struct DATA* data,struct ADDRESS* addr){
    for(int i = p_level-1;i>=0;i--){
        struct DATA* new_data = build_func[i](addr);
        data_union(new_data,data);
        data = new_data;
    }
    return data;
}

struct ARP_P* build_arp(struct ADDRESS* addr){
    struct ARP_P* arp = (struct ARP_P*) calloc(1,sizeof(struct ARP_P));
    //设置arp协议基本属性
    arp->hw_type = ARP_TYPE_ETHE;
    arp->p_type = ARP_PROTOCOL_TYPE_IP;
    arp->hw_addr_len = MAC_ADDR_LEN;
    arp->hw_addr_len = IP_ADDR_LEN;
    //设置arp地址
    //问题，无法解决大端和小端的表示问题
    for(int i = 0;i<MAC_ADDR_LEN;i++) arp->from_py_addr[i] = addr->mac_addr_from[i],arp->to_py_addr[i] = addr->mac_addr_to[i];
    for(int i=  0;i<IP_ADDR_LEN;i++) arp->from_ip_addr[i] = addr->ip_addr_from[i],arp->to_ip_addr[i] = addr->ip_addr_to[i];
    return arp;
}

struct DATA* build_mac_head(struct ADDRESS* addr){
    //为协议分配内存
    struct DATA* new_data = (struct DATA*)calloc(1,sizeof(struct DATA));
    struct mac_head* mac_head = (struct mac_head*)calloc(1,sizeof(struct mac_head));
    for(int i = 0;i<MAC_ADDR_LEN;i++) mac_head->from[i] = addr->mac_addr_from[i],mac_head->to[i] = addr->mac_addr_to[i];
    new_data->type = MAC;
    return new_data;
}


