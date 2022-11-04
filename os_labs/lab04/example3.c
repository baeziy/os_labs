#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main(int argc, char *argv[]){
    pid_t pid;
    pid = fork();
    if (pid>0){
      //  wait(NULL);
        printf("\nI am fine son\n");
    }
    else if (pid==0){
        printf("\nHow are you dad?\n");
        sleep(1);
    }

    return 0;
}
