#ifndef DEFN
#define DEFN

#include<pcap.h>
#include "protocol.h"

typedef unsigned int uint;
struct data_link{
    void* data;
    uint len;
    uint type;
    struct data_link* next;
};

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
struct data_link* build_mac_head(struct ADDRESS* from,struct ADDRESS* to);
struct data_link* build_ip_head(struct ADDRESS* from,struct ADDRESS* to);
struct data_link* build_tcp_head(struct ADDRESS* from,struct ADDRESS* to);
struct data_link* build_udp_head(struct ADDRESS* from,struct ADDRESS* to);
struct data_link* build_arp_head(struct ADDRESS* from,struct ADDRESS* to);
void* build_protocol(uint type);
//Instrument
char* judge_ip_variety(uint variety);

//send_opt

void send_opt(uint pro_type,pcap_if_t* device_inf,pcap_t* device,struct ADDRESS* from,struct ADDRESS* to);
#endif