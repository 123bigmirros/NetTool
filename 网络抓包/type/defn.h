#ifndef DEFN
#define DEFN

#include<pcap.h>
#include "protocol.h"
#include "variety.h"
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

void send(pcap_t* device,struct DATA* data,struct ADDRESS* addr);

//Tool
//data_link_opt
void data_link_add(struct DATA* new,struct DATA* old,int len,void* data);
void data_union(struct DATA* new_data,struct DATA* old_data);
struct DATA* create_DATA(void* data,int len,enum P_TYPE type);
//
//arp_opt
void arp_cmd(int argc,u_char* args[],struct ADDRESS*addr);
void arp_model_judge(u_char* to_mac,u_char* to_ip);
//init
void init();

//terminal
void teminal();

#endif