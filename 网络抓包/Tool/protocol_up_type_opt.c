#include"../type/defn.h"


char* judge_ip_variety(uint variety){
    switch (variety){
        case 1:return "ICMP";
        case 2:return "IGMP";
        case 3:return "GGP";
        case 5:return "ST";
        case 6:return "TCP";
        case 8:return "EGP";
        case 9:return "IGP";
        case 11: return "NVP";
        case 17: return "UDP"; 
        default: return "NULL";
        break;
    }
}
void setup_mac_type_field(void* protocol,enum P_TYPE upper){
    struct MAC_HEAD *p = (struct MAC_P*) protocol;
    for(int i = 0;i<sizeof(p->type);i++){
        p->type[i] = mac_type[upper][i];
    }
}
