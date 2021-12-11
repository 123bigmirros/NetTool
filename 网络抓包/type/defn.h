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
void cst_arp(u_char *bytes,struct ARP* p);
void cst_ip(u_char* bytes,struct IP* p);

//build
struct DATA* build(enum P_TYPE* build_oder[10],struct ADDRESS* addr,u_char* data);
struct DATA* build_mac_head(struct ADDRESS* addr,struct DATA* data);
struct DATA* build_ip_head(struct ADDRESS* addr,struct DATA* data);
struct DATA* build_tcp_head(struct ADDRESS* addr,struct DATA* data);
struct DATA* build_udp_head(struct ADDRESS* addr,struct DATA* data);
struct DATA* build_arp(struct ADDRESS* addr,struct DATA* data);
void* build_protocol(uint type);
//Instrument
char* judge_ip_variety(uint variety);

//send_opt

void send_opt(uint pro_type,pcap_if_t* device_inf,pcap_t* device,struct ADDRESS* addr);


#endif