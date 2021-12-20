#include "../type/init_variety.h"
//用于DATA数据结构的基本操作
void data_link_add(struct DATA* new,struct DATA* old,int len,void* data){
    new->data = data,new->len = len+(data==NULL?0:old->len);
    new->next = old;
}

void data_union(struct DATA* new_data,struct DATA* old_data){
    new_data->len+=old_data->len;
    new_data->next = old_data;
}

struct DATA* create_DATA(void* data,int len,enum P_TYPE type){
    struct DATA* new_data = (struct DATA*) calloc(1,sizeof(struct DATA));
    new_data->data = data;
    new_data->len = len;
    new_data->type = type;
}

