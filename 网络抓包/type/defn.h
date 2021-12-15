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
struct DATA* build(enum P_TYPE* build_order,struct ADDRESS* addr,struct DATA* data);
struct DATA* build_mac_head(struct ADDRESS* addr,struct DATA* data);
struct DATA* build_ip_head(struct ADDRESS* addr,struct DATA* data);
struct DATA* build_tcp_head(struct ADDRESS* addr,struct DATA* data);
struct DATA* build_udp_head(struct ADDRESS* addr,struct DATA* data);
void build_arp(struct ADDRESS* addr,struct ARP_P* arp);
//Instrument
char* judge_ip_variety(uint variety);

//send_opt

void send(pcap_t* device,struct DATA* data);

//Tool
//data_link_opt
void data_link_add(struct DATA* new,struct DATA* old,int len,void* data);
void* data_link_union(struct DATA* data);
struct DATA* get_data(void* data,int len);
//
//arp_opt
void arp_cmd(u_char* arg,struct ADDRESS*addr);
//init
void init();


#endif