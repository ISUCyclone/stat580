#include <stdio.h>
#include <stdlib.h>

void dgesv_(int *n, int *NRHS, double *A, int *LDA,
			int *IPIV, double *B, int *LDB, int *INFO);
			
void dgemm_(char *TRANSA, char *TRANSB, int *M, int *n,
			int *K, double *ALPHA, double *A, int *LDA,
			double *B, int *LDB, double *BETA, double *C, int *LDC);

int main(int argc, char *argv[]){
	char *filename = argv[1];
	FILE *fp = fopen(filename,"r");
	char ch; int lines =0, ii;
	
	while(!feof(fp)){
		ch = fgetc(fp);
		if(ch == '\n')
			lines++;
	}
	
	int N = lines, P = 2;
	
	rewind(fp);
	double y[lines],x1[lines],x2[lines];
	for(ii = 0; ii<lines; ii++){
		fscanf(fp,("%lf %lf %lf\n"), y+ii, x1+ii, x2+ii);
	}
	
	double *Y = y;
	double X[lines][2];
	for(ii = 0;ii < lines; ii++){
		X[ii][0] = x1[ii];
		X[ii][1] = x2[ii];
	}
	
	char transA = 'T', transB = 'N';
	int i, j, rowXt = P+1, colX = P+1, colXt = N, col = 1, ipiv[P+1], info;
	double alpha = 1, X1[N*(P+1)], Beta =0, XX[(P+1)*(P+1)], XY[P+1];
	for(i=0; i<N; i++)
	{
		X1[i] = 1;
		for(j=0; j<P; j++)
		{
			X1[(j+1)*N+i] = X[i][j];
		}
	}
	
	dgemm_(&transA, &transB, &rowXt, &colX, &colXt, &alpha, X1, &colXt, X1, &colXt, &Beta, XX, &rowXt);
	dgemm_(&transA, &transB, &rowXt, &col, &colXt, &alpha, X1, &colXt, Y, &colXt, &Beta, XY, &rowXt);
	
	dgesv_(&rowXt, &col, XX, &rowXt, ipiv, XY, &rowXt, &info);
	
	printf("The regression coefficients: ");
	
	char *intercept = argv[2];
	if(atoi(intercept) == 1){
		for(i=0; i <(P+1); i++)
			printf("%.6f\t", XY[i]);
		printf("\n");
	}
	else if(atoi(intercept) == 0){
		for(i=1; i <(P+1); i++)
			printf("%.6f ", XY[i]);
		printf("\n");
	}
	return 0;
}