//Routing table Manager process
// It is incharge of Layer 3 routing table
//State of routingtable needs to be synchronized accross all cleints at any point of time

#include<stdio.h>
#include<stdlib.h>

typedef enum{
    CREATE,
    UPDATE,
    DELETE
}OPCODE;

typedef struct IPC_Project
{
    char dest[16];
    char mask;
    char gateway_ip[16];
    char oif[32];
}msg_body_t;

typedef struct _sync_msg
{
    /* data */
    OPCODE op_code;
    msg_body_t msg_body; 
}sync_msg_t;



