#include "../type/init_variety.h"
char* judge_ip_variety(uint variety);
void ALS_ARP(u_char* bytes){
    struct ARP_P p;
    cst_arp(bytes,&p);
    printf("%s\n",p.op==1? "ARP������":"ARPӦ����");
    printf("Դmac��ַ:");
    for(int i=  0;i<6;i++){ printf(" %02x",p.from_py_addr[i]);}
    printf("\nĿ��mac��ַ:");
    for(int i=  0;i<6;i++){ printf(" %02x",p.to_py_addr[i]);}
    printf("\nԴip��ַ: ");
    for(int i = 0;i<4;i++){printf("%d%s",p.from_ip_addr[i],i!=3?".":"");}
    printf("\nĿ��ip��ַ: ");
    for(int i = 0;i<4;i++){printf("%d%s",p.to_ip_addr[i],i!=3?".":"");}
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