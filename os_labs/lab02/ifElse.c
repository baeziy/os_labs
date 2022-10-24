#include<stdio.h>

int main(int argc, char** argv){
    double fever;
    printf("\nPlease enter your temperature: ");
    scanf("%lf", &fever);
    if (fever > 98.6){
        printf("You have a high fever\n");
        printf("Take some medicine\n\n");
    }
    else if (fever == 98.6)
        printf("Your temperature is normal\n\n");
    else
        printf("Your temperature is low\n\n");

    return 0;
}