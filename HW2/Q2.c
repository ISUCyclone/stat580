#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(){
	int i;
	i = 1;
	float x, y;
	while(i<=1){
		y = rand()/(float)RAND_MAX;
		x = 10 * pow(y, (float) 1/3);
		printf("%f\n", x);
		i++;
	}
	return 0;
}