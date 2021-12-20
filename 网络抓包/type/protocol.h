#ifndef PROTOCOL
#define PROTOCOL
#include<pcap.h>
#include "variety.h"
struct DATA{
    void* data;
    uint len;
    enum P_TYPE type;
    struct data_link* next;
};
struct ADDRESS{
    u_char mac_addr_from[6];
    u_char ip_addr_from[4];
    u_char mac_addr_to[6];
    u_char ip_addr_to[4];
    u_char port_from[2];
    u_char port_to[2];
};
//ARP结构
struct ARP_P{
    unsigned int hw_type:16;
    unsigned int p_type:16;
    unsigned int hw_addr_len:8;
    unsigned int p_len:8;
    unsigned int op:16;
    u_char from_py_addr[6];
    u_char from_ip_addr[4];
    u_char to_py_addr[6];
    u_char to_ip_addr[4];
};
//IP结构
struct IP_P{
        uint edition:4;
        uint head_length:4;
        uint service:8;
        uint total_length:16;
        uint identification:16;
        uint flag_and_offset:16;
        uint ttl:8;
        uint protocol:8;
        uint head_checksum:16;
        u_char from_ip[4];
        u_char to_ip[4];
        u_char* variety;
        u_char* data;
};

struct MAC_HEAD{
    u_char to[6]; //目的地址
    u_char from[6]; //源地址

    u_char type[2]; //eh_type的值需要考察上一层的协议，如果为ip则为0×0800
};
 struct IP_HEAD{
    u_char h_verlen; //ip头部长度（按4字节对齐）
    u_char tos; //服务类型
    unsigned short total_len; //总长度（包含IP数据头，TCP数据头以及数据）
    u_char version:4; //一般IP类型为IPv4
    unsigned short ident; //ID定义单独IP
    unsigned short frag_and_flags;//标志位偏移量
    u_char ttl; //生存时间
    u_char proto; //协议类型
    unsigned short checksum; //检查和
    unsigned int sourceIP; //源IP地址
    unsigned int destIP; //目的IP地址

};

struct tsd_head{
    u_char saddr[4]; //源地址
    u_char daddr[4]; //目的地址
    char mbz; //置空
    char ptcl; //协议类型
    u_char tcpl[2]; //数据包长度
};
struct udp_hdr
{
    u_char source[2]; /* source port */
    u_char dest[2]; /* destination port */
    u_char len[2]; /* udp length */
    u_char checkl[2]; /* udp checksum */
};

#endif