#include<stdio.h>

int main(int argc, char** argv){
   printf("Even numbers from 0 to 10 are: ");
   for(int i = 0; i<=10; i+=2){
    printf("%d", i);
    if(i!=10)
    printf(", ");
   }
    return 0;
}