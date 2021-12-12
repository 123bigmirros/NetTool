#include "../type/protocol.h"
#include "../type/init_variety.h"
#include "../type/protocol_variety.h"
#include<stdlib.h>
void add(struct DATA* new,struct DATA* old,int len,void* data){
    new->data = data,new->len = len;
    new->next = old;
}
struct DATA* build(enum P_TYPE* build_order,struct ADDRESS* addr,struct DATA* data){
    for(int i = 0;build_order[i]!=-1;i++){
        enum P_TYPE type = build_order[i];
        data = build_func[type](addr,data);
    }
    return data;
}

struct DATA* build_arp(struct ADDRESS* addr,struct DATA* data){
    struct DATA* new_data = (struct DATA*)calloc(1,sizeof(struct DATA));
    struct ARP_P* arp = (struct ARP*)calloc(1,sizeof(struct ARP_P));
    arp->hw_type = ARP_TYPE_ETHE;
    arp->p_type = ARP_PROTOCOL_TYPE_IP;
    arp->hw_addr_len = MAC_ADDR_LEN;
    arp->hw_addr_len = IP_ADDR_LEN;
    for(int i = 0;i<MAC_ADDR_LEN;i++) arp->from_py_addr[i] = addr->mac_addr_from[i],arp->to_py_addr[i] = addr->mac_addr_to[i];
    for(int i=  0;i<IP_ADDR_LEN;i++) arp->from_ip_addr[i] = addr->ip_addr_from[i],arp->to_ip_addr[i] = addr->ip_addr_to[i];
}


