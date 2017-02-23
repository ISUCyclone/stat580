#include <stdio.h>

#define N 10

int main(){
	int i,j,k, mid;
	double x[N] = {3.1,-1.2,5.3,1,4.4,21,3,7,-1.2,3.2}, tmp;
	
	
	for(i=1;i<N;i++){
		for(j=0;j<i;j++){
			if(x[i] < x[j]){
				tmp = x[i];
				for(k = i; k > j;k--)
					x[k] = x[k-1];
				x[j] = tmp;
				break;
			}
		}
	}
	printf("Sorted Data:\n");
	for(i = 0;i < N;i++)
		printf("%f ", x[i]);
	
	printf("\nMedian:\n");
	if(N%2){
		mid = (N+1)/2;
		printf("%f", x[mid-1]);
	}
	else{
		printf("%f", (x[N/2-1]+x[N/2])/2);
	}
	
	return 0;
}