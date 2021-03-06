#ifndef VARIETY
#define VARIETY

typedef unsigned int uint;

const int MAC_LEN = 6;

enum P_TYPE{MAC,IP,ARP};
const char *FROM = "FROM";
const char *TO = "TO";
const char *UNDEFINE = "UNDEFINE";

// universal
#define MODEL_LEN 32



//ARP
uint ARP_MODE = 1;
enum ARP_MODE_TYPE  {SPOOFING};
#define ARP_TYPE_ETHE 0x01 //硬件类型：以太网
#define ARP_PROTOCOL_TYPE_IP 0x0806 //协议类型 : IP
#define ARP_REQUEST 0x01 //操作类型:ARP请求
#define ARP_RESPONSE 0x02 //操作类型：ARP响应
#define ARP_LEVEL 1
#define ARP_REQUEST_OP 1
#define ARP_RESPONSE_OP 2
//mac 
#define MAC_ADDR_LEN 6
const u_char mac_type[][3] ={
    [ARP]={0x08,0x06,'\0'}
};


//IP
#define IPV4_ADDR_LEN 4

#endif