#include<stdio.h>
#include<signal.h>
#include<stdlib.h>

int main(){
    // int pid;
    // pid = system("pidof -s Kill_receiver");
    // printf("Pid of Kill reciever %d\n",pid);
    kill(pid,SIGUSR1);
    scanf("\n");
    return 0;
}