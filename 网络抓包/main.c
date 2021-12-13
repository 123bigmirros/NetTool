#include<stdio.h>
#include<pcap.h>
#include"./type/defn.h"
void callback(u_char *user, const struct pcap_pkthdr *h,const u_char *bytes);
int main()
{

   
        pcap_if_t *alldevs; 
        char errBuf[PCAP_ERRBUF_SIZE];//保存错误信息
        pcap_t* device;
        bpf_u_int32  net_ip; 
        bpf_u_int32  net_mask;
        if(pcap_findalldevs(&alldevs, errBuf) == -1){
                printf("查找设备失败"); return 0;
        }
        int cnt = 0;
        for(pcap_if_t *d= alldevs; d != NULL; d= d->next)
        {
             
                //device = pcap_open_live(d->name,65535,1,0,errBuf);
                
                pcap_lookupnet(d->name,&net_ip,&net_mask,errBuf);
               
                printf("%s %d %s %u\n",d->name,d->addresses,d->description,net_ip);
               
                if(cnt==4) {
                        device = pcap_open_live(d->name,65535,1,0,errBuf);
                        if(!device) printf("打开失败 %s\n\r",errBuf);
                        //send_opt(d,device,0);
                        //pcap_loop(device,-1,callback,NULL);
                }
                ++cnt;
        }
        return 0;
}
void callback(u_char *user, const struct pcap_pkthdr *h,const u_char *bytes){
        analyse(h,bytes);
}
