#ifndef DEFN
#define DEFN

#include<pcap.h>
#include "protocol.h"
typedef unsigned int uint;


void callback(u_char *user, const struct pcap_pkthdr *h,const u_char *bytes);
//Analyse
void analyse(const struct pcap_pkthdr *h,const u_char *bytes);
enum P_TYPE judge_type(u_char *bytes);

void ALS_ARP(u_char* bytes);
void ALS_IP(u_char* bytes);
//string.
void print(const char* pre,const u_char* bytes,int b,int len);

//construct_protocol
void cst_arp(u_char *bytes,struct ARP_P* p);
void cst_ip(u_char* bytes,struct IP_P* p);

//build
struct DATA* build(int p_level,struct DATA* data,struct ADDRESS* addr);
struct DATA* build_mac_head(struct ADDRESS* addr);
struct DATA* build_ip_head(struct ADDRESS* addr);
struct DATA* build_tcp_head(struct ADDRESS* addr);
struct DATA* build_udp_head(struct ADDRESS* addr);
struct ARP_P* build_arp(struct ADDRESS* addr);
//Tool
char* judge_ip_variety(uint variety);
void setup_mac_type_field(void* protol,enum P_TYPE upper);
void get_address(struct ADDRESS* addr,u_char* to_mac,u_char* to_ip);
//send_opt

void send_data(struct DATA* data);

//Tool
//data_link_opt
void* DATA_t_byte(struct DATA* head);
void data_union(struct DATA* new_data,struct DATA* old_data);
struct DATA* create_DATA(u_char* data,int len,enum P_TYPE type);
void free_DATA(struct DATA* head);
//
//arp_opt
void arp_cmd(int argc,u_char* args[],struct ADDRESS*addr);
void arp_model_judge(u_char* to_mac,u_char* to_ip);
//init
void init();

//terminal
void teminal();

#endif