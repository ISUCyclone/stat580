#include <stdio.h>

int main()
{
	int i, j, count;
	i = 0;count = 0;

	j = getchar();
	while(j != EOF){
		if (j == 9 || j == 10 || j == 32)
			j = 0;
		else
			j = 1;

		if((j-i) == 1)
			count++;
		i = j;
		j = getchar();
	}
	printf("There are %d words\n", count);
	return 0;
}