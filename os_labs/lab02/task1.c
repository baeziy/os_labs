#include<stdio.h>
int main(int argc, char** argv)
{
	double zeta[30] = {1.1, 2.2, 3.3};	
	printf("Please enter nth number: ");
	int n;
	scanf("%d", &n);
	zeta[n] = 0.5 * zeta[n-3] + 0.3 * zeta[n-2] + 0.2 * zeta[n-1];

	for(int i = 0; i < 30; i++){
		printf("%f, ", zeta[i]);
	}
	return 0;
}
