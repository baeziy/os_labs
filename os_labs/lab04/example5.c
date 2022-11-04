#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main(int argc, char *argv[]){
    pid_t pid;
    pid = fork();
    if (pid>0){
        //wait(NULL);
        for(int i=0; i<100000;i++)
            printf(".");
    }
    else if (pid==0){
        for(int i=0; i<100000;i++)
            printf("/");
    }

    return 0;
}
