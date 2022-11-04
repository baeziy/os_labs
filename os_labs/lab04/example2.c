#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main(int argc, char *argv[]){
    pid_t pid;
    pid = fork();
    if (pid>0){
        printf("\nIn Section-A, my PID is %d\n",getpid());
    }
    else if (pid==0){
        printf("\nIn Section-B, my PID is %d\n",getpid());
        sleep(1);
    }

    return 0;
}
