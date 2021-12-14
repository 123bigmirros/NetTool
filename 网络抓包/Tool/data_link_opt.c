#include "../type/defn.h"
void data_link_add(struct DATA* new,struct DATA* old,int len,void* data){
    new->data = data,new->len = len+(data==NULL?0:old->len);
    new->next = old;
}

void* data_link_union(struct DATA* data){
    u_char* d = (u_char*)calloc(data->len,sizeof(u_char));
    int len = 0;
    while(data!=NULL){
        u_char* now_data = (u_char*) data->data;
        for(int i = 0;i<data->len;i++) d[len++] = now_data[i];
        data = data->next;
        
    }
    return (void*)d;
}

