#include <stdio.h>
#include <time.h>
#define MATHLIB_STANDALONE
#include <Rmath.h>

int main(){
	int i,n;
	n = 5;

	float x,y;
	
	set_seed(time(NULL), 123456);
	
	for(i = 1; i <= n; i++)
	{
		x = unif_rand();
		y = R_pow(10, x);
		printf("%f\n", y);
	}
	return 0;
}
