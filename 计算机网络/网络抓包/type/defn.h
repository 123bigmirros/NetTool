#ifndef DEFN
#define DEFN

#include<pcap.h>
#include "protocol.h"

typedef unsigned int uint;



void callback(u_char *user, const struct pcap_pkthdr *h,const u_char *bytes);
//Analyse
void analyse(const struct pcap_pkthdr *h,const u_char *bytes);
TYPE_P judge_type(u_char *bytes);

void ALS_ARP(u_char* bytes);
void ALS_IP(u_char* bytes);
//string.
void print(const char* pre,const u_char* bytes,int b,int len);

//construct_protocol
void cst_arp(u_char *bytes,struct ARP* p);
void cst_ip(u_char* bytes,struct IP* p);

//construct_head
void cst_mac_head(struct mac_header* h,struct ADDRESS* from,struct ADDRESS* to);
void cst_ip_head(struct ip_head*h,struct ADDRESS* from,struct ADDRESS* to);
void cst_tcp_head();
void cst_udp_head();
void cst_arp_head();
//Instrument
char* judge_ip_variety(uint variety);

//send_opt
//void send_opt(pcap_if_t* device_inf,pcap_t* device,uint pro_type);
#endif