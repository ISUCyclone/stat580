#include <stdio.h>
#include <math.h>
#define P0 0.01
#define P1 0.5
#define PLEN 10
#define N 5

int factorial(int n){
	if(n == 0 || n == 1)
		return 1;
	else
		return n * factorial(n-1);
}

float binomial(int x, float p){
	float density;
	density = factorial(N)/(factorial(x) * factorial(N-x)) * pow(p,x) * pow(1-p, N-x);
	return density;
}

int main()
{
	int i,j,row;
	double colStep, colVar, density;
	colStep = (P1 - P0)/(PLEN - 1);

	printf("x\\p\t");

	colVar = P0;
	for(i=1; i<=PLEN; i++){
		printf("%f\t", colVar);
		colVar = colVar + colStep;
	}
	printf("\n");

	for(j = 0;j <= N; j++){
		printf("%d\t", j);
		colVar = P0;
		for(i = 1; i <=PLEN; i++){
			density = binomial(j, colVar);
			colVar = colVar + colStep;
			printf("%.4f\t", density);
		}
		printf("\n");
	}
	return 0;
}
