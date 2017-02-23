#include <stdio.h>

#define N 16
#define P 2

void dgesvd_(char *JOBU, char *JOBVT, int *M, int *n, double *A, int *LDA, double *S, double *U, int *LDU, double *VT, int *LDVT, double *WORK, int *LWORK, int *INFO);
void dgemm_(char *TRANSA, char *TRANSB, int *M, int *n,
			int *K, double *ALPHA, double *A, int *LDA,
			double *B, int *LDB, double *BETA, double *C, int *LDC);
int main()
{
	double X[N][P] = {{83,107.608},
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
					 
	double colMean[2];
	colMean[0] = 0;colMean[1] = 0;
	double Z[N*P];
	
	int i,j;
	for(i=0; i<P; i++)
		for(j=0; j<N; j++)
			colMean[i] += X[j][i];
	
	colMean[0] = colMean[0]/N;
	colMean[1] = colMean[1]/N;
	
	for(i=0; i<P; i++)
		for(j=0; j<N; j++){
			Z[i*N+j] = X[j][i] - colMean[i];
		}
	
	char jobu = 'S', jobvt = 'S';
	int m = N, n = P, lda = N, ldu = N, ldvt = P, lwork = -1, info;
	double s[P], u[ldu*P], vt[ldvt*P], work;
		
	dgesvd_(&jobu, &jobvt, &m, &n, Z, &lda, s, u, &ldu, vt, &ldvt, &work, &lwork, &info);
	
	lwork = (int) work;
	double newWork[lwork];
	dgesvd_(&jobu, &jobvt, &m, &n, Z, &lda, s, u, &ldu, vt, &ldvt, newWork, &lwork, &info);
	
	
	double Sigma[P*P];
	Sigma[0] = s[0]; Sigma[3] = s[1]; Sigma[1] = 0; Sigma[2] = 0;
	
	char tranA = 'N', tranB = 'N';
	int udR = N, udC = P, k = P;
	double alpha = 1, beta =0, ud[N*P];

	dgemm_(&tranA, &tranB, &udR, &udC, &k, &alpha, u, &udR,
			Sigma, &udC, &beta, ud, &udR);
			
	for(j = 0;j < N;j++){
		for(i = 0;i < P;i++)
			printf("%f ", ud[j+N*i]);
		printf("\n");
	}
	return 0;
}