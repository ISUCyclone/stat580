#include <stdio.h>

int main()
{
	int c;
	c = getchar();
	while(c != EOF){
		if(c == 32){
			putchar(c);
			c = getchar();
		}
		else{
			putchar(c+2);
			c = getchar();
		}
	}
	return 0;
}