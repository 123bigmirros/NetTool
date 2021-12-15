#include "../type/init_variety.h"
#include <stdlib.h>
static u_char cmd_type[][10] = {"req","rep"};
void arp_cmd(u_char* arg,struct ADDRESS*addr){
    struct ARP_P arp;
    build_arp(addr,&arp);
    
}

struct ADDRESS* get_arp_addr(struct ARP_P* p){

}