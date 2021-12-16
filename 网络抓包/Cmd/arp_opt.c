#include "../type/init_variety.h"
#include <stdlib.h>

static void arp_req_set(struct ARP_P* p){
    p->op = ARP_REQUEST_OP;
}
static void arp_req_set(struct ARP_P* p){
    p->op = ARP_RESPONSE_OP;
}
static u_char cmd_arg[][10] = {"req","rep"};
static void (*p[])(struct ARP_P* p) = {arp_req_set,arp_req_set};

void arp_cmd(int argc,u_char* args[],struct ADDRESS*addr){
    struct ARP_P arp;
    build_arp(addr,&arp);
    for(int i = 0;i<argc;i++){
        for(int j = 0;j<sizeof_2d_array(cmd_arg);j++){
            if(strcmp(args[i],cmd_arg[j])==0) p[j](&arp);
        }
    }
}

struct ADDRESS* get_arp_addr(struct ARP_P* p){

}