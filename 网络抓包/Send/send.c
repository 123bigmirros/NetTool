#include"../type/defn.h"
#include"../type/protocol.h"
#include"pcap.h"

void send(pcap_t* device,struct DATA* data){
    pcap_inject(device,data_link_union(data),data->len);
}
