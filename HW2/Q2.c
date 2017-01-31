#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
int main()
{
	srand(time(0));
	float x,y;
	x = (float)rand()/RAND_MAX;
	y = 10* pow(x,(float) 1/3);
	printf("%f\n",y);
	return 0;
}
