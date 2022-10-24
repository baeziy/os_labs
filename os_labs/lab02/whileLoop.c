#include<stdio.h>

int main(int argc, char** argv){
    int j=2, FibonacciCount = 10-2, f[10];
    f[0] = 0; f[1] = 1;
    printf("\nFirst 10 Fibonacci Numbers are: ");
    printf("%d, %d", f[0], f[1]);
    while(j< FibonacciCount){
        f[j] = f[j-1]+f[j-2];
        printf(", %d", f[j]);
        j++;
        printf("%d",j-2);
    }
    printf("\n\n");

    return 0;
}