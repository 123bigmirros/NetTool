#include "../type/protocol.h"
#include "../type/init_variety.h"
#include "../type/protocol_variety.h"
#include<stdlib.h>

struct DATA* build(enum P_TYPE* build_order,struct ADDRESS* addr,struct DATA* data){
    for(int i = 0;build_order[i]!=-1;i++){
        enum P_TYPE type = build_order[i];
        data = build_func[type](addr,data);
        data->type = type;
    }
    return data;
}

struct DATA* build_arp(struct ADDRESS* addr,struct DATA* data){
    //为协议分配内存
    struct DATA* new_data = (struct DATA*)calloc(1,sizeof(struct DATA));
    struct ARP_P* arp = (struct ARP*)calloc(1,sizeof(struct ARP_P));
    //设置arp协议基本属性
    arp->hw_type = ARP_TYPE_ETHE;
    arp->p_type = ARP_PROTOCOL_TYPE_IP;
    arp->hw_addr_len = MAC_ADDR_LEN;
    arp->hw_addr_len = IP_ADDR_LEN;
    //设置arp地址
    //问题，无法解决大端和小端的表示问题
    for(int i = 0;i<MAC_ADDR_LEN;i++) arp->from_py_addr[i] = addr->mac_addr_from[i],arp->to_py_addr[i] = addr->mac_addr_to[i];
    for(int i=  0;i<IP_ADDR_LEN;i++) arp->from_ip_addr[i] = addr->ip_addr_from[i],arp->to_ip_addr[i] = addr->ip_addr_to[i];
    add(new_data,data,sizeof(struct ARP_P),data);
    return new_data;
}

struct DATA* build_mac_head(struct ADDRESS* addr,struct DATA* data){
    //为协议分配内存
    struct DATA* new_data = (struct DATA*)calloc(1,sizeof(struct DATA));
    struct mac_head* mac_head = (struct mac_head*)calloc(1,sizeof(struct mac_head));
    
    for(int i = 0;i<MAC_ADDR_LEN;i++) mac_head->from[i] = addr->mac_addr_from[i],mac_head->to[i] = addr->mac_addr_to[i];
    mac_head->eh_type[0] = mac_p_type[data->type][0],mac_head->eh_type[1] = mac_p_type[data->type][1];
    add(new_data,data,sizeof(struct mac_head),data);
    return new_data;
}


