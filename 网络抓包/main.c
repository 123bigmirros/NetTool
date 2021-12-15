#include<stdio.h>
#include<pcap.h>
#include"./type/init_variety.h"

int main()
{
        pcap_if_t *alldevs; 
        char errBuf[PCAP_ERRBUF_SIZE];//保存错误信息
        
        
        if(pcap_findalldevs(&alldevs, errBuf) == -1){
                printf("查找设备失败\n"); return 0;
        }
        int cnt = 0;
        for(pcap_if_t *d= alldevs; d != NULL; d= d->next)
        {
                              
                if(cnt==4) {
                        device_info = d;             
                        //if(!device) printf("打开失败 %s\n\r",errBuf);
                        //send_opt(d,device,0);
                        //pcap_loop(device,-1,callback,NULL);
                }
                ++cnt;
        }
        if(device_info) init();
        else printf("没有打开设备\n");
        return 0;
}
void callback(u_char *user, const struct pcap_pkthdr *h,const u_char *bytes){
        analyse(h,bytes);
}
