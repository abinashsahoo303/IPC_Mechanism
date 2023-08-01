#include<stdio.h>
#include<signal.h>
#include<stdlib.h>

void signal_catch(int);

int main(){
    int ret;
    ret = signal(SIGINT, signal_catch);

    if(ret == SIG_ERR){
        printf("Error: unable to set sig handler\n");
        exit(0);
    }

    printf("Going to raise a signal\n");
    ret = raise(SIGINT);

    if(ret != 0){
        printf("Error: unable to raise SIGINT signal\n");
        exit(0);
    }

    printf("Exiting...\n");
    return(0);
}

void signal_catch(int signal){
    printf("!! signal caught !!\n");
}