#include "../type/init_variety.h"
void cst_arp(u_char *bytes,struct ARP_P* p){
    p->hw_type = unit_8_to_16(bytes[0],bytes[1]);
    p->p_type = unit_8_to_16(bytes[2],bytes[3]);
    p->hw_addr_len = bytes[4];
    p->p_len = bytes[5];
    p->op = unit_8_to_16(bytes[6],bytes[7]);
    for(int i = 0;i<6;i++) p->from_py_addr[i] = bytes[8+i];
    for(int i = 0;i<4;i++) p->from_ip_addr[i] = bytes[14+i];
    for(int i = 0;i<6;i++) p->to_py_addr[i] = bytes[18+i];
    for(int i = 0;i<4;i++) p->to_ip_addr[i] = bytes[24+i];
}
void cst_ip(u_char* bytes,struct IP_P* p){
    p->edition = unit_8_to_pre4(bytes[0]);
    p->head_length = unit_8_to_suf4(bytes[0]);
    p->service = bytes[1];
    p->total_length = unit_8_to_16(bytes[2],bytes[3]);
    p->identification = unit_8_to_16(bytes[4],bytes[5]);
    p->flag_and_offset = unit_8_to_16(bytes[6],bytes[7]);
    p->ttl = bytes[8];
    p->protocol = bytes[9];
    p->head_checksum = unit_8_to_16(bytes[10],bytes[11]);
    for(int i= 0;i<4;i++){
            p->from_ip[i] = bytes[12+i];
            p->to_ip[i] = bytes[16+i];
    }
    p->variety = &bytes[20];
    p->data =( bytes+p->head_length*4);
}