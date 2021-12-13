#ifndef VARIETY
#define VARIETY

typedef unsigned int uint;

const int MAC_LEN = 6;

enum P_TYPE{MAC,ARP,IP};
const char *FROM = "FROM";
const char *TO = "TO";
const char *UNDEFINE = "UNDEFINE";

const u_char mac_p_type[][3] ={
    [ARP]{0x08,0x06,'\0'}};//,{0x08,0x00,'\0'}};//ARP




#endif