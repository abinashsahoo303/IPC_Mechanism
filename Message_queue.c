//A msg queue can support one client process
// clinet can deque messages from more than one msg Queues
// No limitation on Server process

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<mqueue.h>
#include<errno.h>

#define MAX_MSGSIZE 256
#define MSG_BUF_SIZE (MAX_MSGSIZE+10)

int main(int argc,char **argv){
    char buf[MSG_BUF_SIZE];
    int recfd = 0;

    if(argc <= 1){
        printf("Provide msgQ name: format </msgq-name>\n");
        return 0;
    }

    memset(buf, 0, MSG_BUF_SIZE);
    printf("Enter msg to be sent to receiver %s\n",argv[1]);
    scanf("%s",buf);

    if((recfd = mq_open(argv[1],O_WRONLY | O_CREAT, 0, 0)) == -1){
        printf("Client: mq_open failed, errno =%d\n", errno);
        exit(1);
    }

    if(mq_send(recfd,buf,strlen(buf)+1,0)== -1){
        printf("Clinet: Not able to send message to server");
        exit(1);
    }

    mq_close(recfd);
    return 0;
}