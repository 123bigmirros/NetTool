#include"../type/defn.h"
#include "../type/protocol.h"
#include<pcap.h>
#include<string.h>
const void (*p_func[])(u_char *bytes) = {ALS_ARP,ALS_IP};
const char *FROM = "FROM";
const char *TO = "TO";
 const char *UNDEFINE = "UNDEFINE";
static const u_char p_type[][3] ={{0x08,0x06,'\0'}};//,{0x08,0x00,'\0'}};//ARP
void analyse(const struct pcap_pkthdr *h,const u_char *bytes){


    TYPE_P pnum = judge_type(bytes);//判断链路层上层协议类型
    //if(pnum==-1) print(UNDEFINE,bytes,2*MAC_LEN+2,h->caplen);
    if(pnum!=-1) {
        printf("caplen: %d\n",h->caplen);
        print(TO,bytes,0,0+MAC_LEN);//打印mac源地址
        print(FROM,bytes,MAC_LEN,MAC_LEN+MAC_LEN);//打印mac目的地址
        p_func[pnum](&(bytes[2*MAC_LEN+2]));
        printf("\n\n");
    }
}

TYPE_P judge_type(u_char *bytes){
    u_char p_kind[3];
    p_kind[0] = bytes[12],p_kind[1] = bytes[13],p_kind[2] = '\0';
    for(int i=  0;i<(int)sizeof(p_type)/sizeof(p_type[0]);i++){
        if(strcmp(p_kind,p_type[i])==0) return i;
    }
    return -1;
}
