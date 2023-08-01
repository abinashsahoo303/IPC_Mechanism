#include<stdio.h>
#include<signal.h>
#include<stdlib.h>

static void sig_handler(int sig){
    printf("Signal %d received\n",sig);
    abort();
}

int main(){
    signal(SIGUSR1, sig_handler);
    scanf("\n");
    return 0;
}