#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main(int argc, char *argv[]){
    pid_t pid;
    printf("\nHi\n");
    sleep(1);
    pid = fork();
    printf("\nHow are you?\n");
    return 0;
}
