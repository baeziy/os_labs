//   1. Course 301-OS-A,
//   2. Muhammad Mustafa Kamal Malik,
//   3. 241610047
//   4. 28/10/2022

#include <stdio.h>
#include <stdlib.h>
 int main(int argc, char *argv[]){
       int n = atoi(argv[3]);
    printf("Mr. %s %s %d, years old\n", argv[1], argv[2], n);
    printf("Fist name '%s' memory address: %p\n", argv[1], (void*)argv[1]);
    return 0;
 }