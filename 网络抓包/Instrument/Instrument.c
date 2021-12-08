#include"../type/defn.h"
char* ICMP = "ICMP",*IGMP = "IGMP",*TCP = "TCP",*UDP = "UDP",*OSPF = "OSPF",*UNKOWN = "UNKOWN";
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