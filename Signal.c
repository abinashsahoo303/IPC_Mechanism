#include <signal.h>
#include<stdio.h>
#include<stdlib.h>

static void ctrlC_sig_handler(int sig)
{
    printf("signal received of ctrl + c");
    printf("Bye bye");
    exit(0);
}

static void abort_signal_handler(int sig)
{
    printf("process is aborted\n");
    printf("Bye Bye\n");
    exit(0);
}

int main(int argc, char **argv)
{
    signal(SIGINT, ctrlC_sig_handler);
    signal(SIGABRT, abort_signal_handler);
    char ch;
    printf("Abort process (y/n) ?\n");
    scanf("%c", &ch);
    if (ch == 'y')
        abort();
    return 0;
}