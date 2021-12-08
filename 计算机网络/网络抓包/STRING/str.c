#include"../type/defn.h"
void print(const char* pre,const u_char* bytes,int b,int e){
        if(pre!=NULL) printf("%s : ",pre);
        while(b!=e) printf("%02x ",bytes[b++]);
        printf("\n");
}