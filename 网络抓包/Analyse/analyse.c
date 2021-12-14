#include "../type/init_variety.h"
#include<pcap.h>
#include<string.h>


void analyse(const struct pcap_pkthdr *h,const u_char *bytes){
    enum P_TYPE pnum = judge_type(bytes);//判断链路层上层协议类型
    //if(pnum==-1) print(UNDEFINE,bytes,2*MAC_LEN+2,h->caplen);
    if(pnum!=-1) {
        //printf("caplen: %d\n",h->caplen);
        //print(TO,bytes,0,0+MAC_LEN);//打印mac源地址
       // print(FROM,bytes,MAC_LEN,MAC_LEN+MAC_LEN);//打印mac目的地址
        p_analyse[pnum](&(bytes[2*MAC_LEN+2]));
        printf("\n\n");
    }
}

enum P_TYPE judge_type(u_char *bytes){
    u_char p_kind[3];
    p_kind[0] = bytes[12],p_kind[1] = bytes[13],p_kind[2] = '\0';
    for(int i=  0;i<(int)sizeof(mac_p_type)/sizeof(mac_p_type[0]);i++){
        if(strcmp(p_kind,mac_p_type[i])==0) return i;
    }
    return -1;
}
