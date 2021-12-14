#include "../type/defn.h"
#include "../type/init_variety.h"
char* judge_ip_variety(uint variety);
void ALS_ARP(u_char* bytes){
    struct ARP_P p;
    cst_arp(bytes,&p);
    if(p.op!=1) return;
    printf("%s\n",p.op==1? "ARP请求报文":"ARP应答报文");
    printf("源mac地址:");
    for(int i=  0;i<6;i++){ printf(" %02x",p.from_py_addr[i]);}
    printf("\n目的mac地址:");
    for(int i=  0;i<6;i++){ printf(" %02x",p.to_py_addr[i]);}
    printf("\n源IP地址: ");
    for(int i = 0;i<4;i++){printf("%d%s",p.from_ip_addr[i],i!=3?".":"");}
    printf("\n目的IP地址: ");
    for(int i = 0;i<4;i++){printf("%d%s",p.to_ip_addr[i],i!=3?".":"");}
    arp_sproofing(&p);
}

void ALS_IP(u_char* bytes){
    struct IP_P p;
    cst_ip(bytes,&p);
    printf("IP protocol\n");
    printf("edition: %02x head_length: %d service: %x\n",p.edition,p.head_length,p.service);
    printf("Total length %d\n",p.total_length);
    printf("identification: %d\n",p.identification);
    if(p.flag_and_offset&(1<<14)) printf("this Ip data disagree slice\n");
    else printf("%s slice offset: %d\n",(p.flag_and_offset&(1<<13))?"Between data":"Ending data",(p.flag_and_offset&0x1fff));
    printf("TTL: %d Upper protocol:%s\n",p.ttl,judge_ip_variety(p.protocol));
    printf("From_Ip: ");
    for(int i = 0;i<4;i++){printf("%d%s",p.from_ip[i],i!=3?".":"");}
    printf("\nAimIp: ");
    for(int i = 0;i<4;i++){printf("%d%s",p.to_ip[i],i!=3?".":"");}      
}