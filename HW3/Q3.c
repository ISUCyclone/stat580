#include <stdio.h>

#define N 16
#define P 2

void dgesv_(int *n, int *NRHS, double *A, int *LDA,
			int *IPIV, double *B, int *LDB, int *INFO);
			
void dgemm_(char *TRANSA, char *TRANSB, int *M, int *n,
			int *K, double *ALPHA, double *A, int *LDA,
			double *B, int *LDB, double *BETA, double *C, int *LDC);

int main()
{
	double Y[N]={60.323, 61.122, 60.171, 61.187,
				 63.221, 63.639, 64.989, 63.761,
				 66.019, 67.857, 68.169, 66.513,
				 68.655, 69.564, 69.331, 70.551};
	double X[N][P] ={{83,107.608},
					 {88.5,108.632},
					 {88.2,109.773},
					 {89.5,110.929},
					 {96.2,112.075},
					 {98.1,113.27},
					 {99,115.094},
					 {100,116.219},
					 {101.2,117.388},
					 {104.6,118.734},
					 {108.4,120.445},
					 {110.8,121.95},
					 {112.6,123.366},
					 {114.2,125.368},
					 {115.7,127.852},
					 {116.9,130.081}};
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
	for(i=0; i <(P+1); i++)
		printf("%.6f\t", XY[i]);
	printf("\n");
	
	return 0;
}
