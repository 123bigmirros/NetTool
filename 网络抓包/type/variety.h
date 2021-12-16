#ifndef VARIETY
#define VARIETY

typedef unsigned int uint;

const int MAC_LEN = 6;

enum P_TYPE{MAC = 1,IP,ARP};
const char *FROM = "FROM";
const char *TO = "TO";
const char *UNDEFINE = "UNDEFINE";

const u_char mac_p_type[][3] ={
    [ARP]{0x08,0x06,'\0'}
};//,{0x08,0x00,'\0'}};//ARP


//ARP
#define PROTOCOL_VARIETY
#define ARP_TYPE_ETHE 0x01 //硬件类型：以太网
#define ARP_PROTOCOL_TYPE_IP 0x0806 //协议类型 : IP
#define ARP_REQUEST 0x01 //操作类型:ARP请求
#define ARP_RESPONSE 0x02 //操作类型：ARP响应
#define ARP_LEVEL 2
#define ARP_REQUEST_OP 1
#define ARP_RESPONSE_OP 2
//mac 
#define MAC_ADDR_LEN 6


//IP
#define IP_ADDR_LEN 4


#endif