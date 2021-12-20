#include "../type/init_variety.h"
#include <stdlib.h>

static void arp_req_set(struct ARP_P* p){
    p->op = ARP_REQUEST_OP;
}
static void arp_req_set(struct ARP_P* p){
    p->op = ARP_RESPONSE_OP;
}
static void arp_spoofing(u_char* to_mac,u_char* to_ip){
    struct ADDRESS addr;
    struct ARP_P* arp;
    get_address(&addr,to_mac,to_ip);
    arp = build_arp(&addr);
    arp_req_set(arp);
    struct DATA* data = create_DATA((void*)arp,sizeof(struct ARP_P),ARP);
    data = build(ARP_LEVEL,data,&addr);
}
static u_char cmd_arg[][10] = {"req","rep"};
static void (*set_field[])(struct ARP_P* p) = {arp_req_set,arp_req_set};
static void (*arp_mode_opt[])(u_char*,u_char*) = {arp_spoofing};
void arp_cmd(int argc,u_char* args[],struct ADDRESS*addr){
    struct ARP_P* arp;
    arp = build_arp(addr);
    for(int i = 0;i<argc;i++){
        for(int j = 0;j<sizeof_2d_array(cmd_arg);j++){
            if(strcmp(args[i],cmd_arg[j])==0) set_field[j](arp);
        }
    }
    struct DATA* data = create_DATA((void*)arp,sizeof(struct ARP_P),ARP);
    data = build(ARP_LEVEL,data,addr);
}
void arp_model_judge(u_char* to_mac,u_char* to_ip){
    for(int i= 0;i<MODEL_LEN;i++){
        if(ARP_MODE&(1<<i)) arp_mode_opt[i](to_mac,to_ip);
    }
}
struct ADDRESS* get_arp_addr(struct ARP_P* p){

}