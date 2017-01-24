#include <stdio.h>
#define ROW 20

int main()
{
	float i, f, c, upper, lower, step;
	upper = 200;lower = 0;
	step = (upper - lower)/(ROW-1);

	i = 1;f = lower;
	printf("F\tC\n");
	while(i <= ROW)
	{
		c = 5 * (f - 32)/9;
		printf("%.2f\t%.2f\n", f, c);
		f = f + step;
		i = i + 1;
	}
	return 0;
}
