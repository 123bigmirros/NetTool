#include "../type/init_variety.h"
#include <stdlib.h>

void data_union(struct DATA* new_data,struct DATA* old_data){
    new_data->len+=old_data->len;
    new_data->next = old_data;
}

struct DATA* create_DATA(u_char* data,int len,enum P_TYPE type){
    struct DATA* new_data = (struct DATA*) calloc(1,sizeof(struct DATA));
    new_data->data = data;
    new_data->len = len;
    new_data->type = type;
}

void* DATA_t_byte(struct DATA* head){
    u_char* data = (u_char*) calloc(head->len,sizeof(u_char));
    int size = 0;
    while(head!=NULL){
        for(int i=  0;i<head->len;i++) data[size++] = head->data[i];
        head = head->next;
    }
    return (void*)data;
}
void free_DATA(struct DATA* head){
    if(head==NULL) return;
    free_DATA(head->next);
    free(head->data);
    free(head);
}  