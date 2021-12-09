#include"../type/defn.h"
#include"../type/protocol.h"
#include"pcap.h"
void send_opt(uint pro_type,pcap_if_t* device_inf,pcap_t* device,struct ADDRESS* from,struct ADDRESS* to){
    
    pcap_inject(device,NULL,0);
}