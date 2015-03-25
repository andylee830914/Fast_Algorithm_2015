#include <stdio.h>
#include <math.h>
#include <time.h>
#define DEBUG 0
#include<stdlib.h>
int main()
{
<<<<<<< HEAD
	int i, j, N=5;
	double x[N],b[N];//,tic,toc;
	clock_t tic,toc;
=======
	int i, j, N=10000;
	double *x,*b,tic,toc; // *x,*b �@������ 
	double **A; 		  // **A �G������

	// x[N], b[N], A[N][N] �ʺAmemory���}�k
	// �R�A�O���馳����A�ʺA�O����S��
	// �]���b�R�A�O���骺�ɭԡAN=1000���ɭԴN�S��k���F�A���ʺA�O����i�H 
	// ���I:�O���餣�@�w�|�����Ʀb�@�_�A�@���u�}N�� 
	x = (double *)malloc(N*sizeof(double)) ; 
	b = (double *)malloc(N*sizeof(double)) ; 
	A = (double **)malloc(N*sizeof(double*)) ; 
	for ( i=0 ; i<N ; ++i)
	{
		A[i] = (double *)malloc(N*sizeof(double)) ; 
	}
	/*
	�t�@�ؤG���x�}���ʺA�O����g�k�A�n�B�A�O����u�n�}�@��(�@���}N^2��)�A�B�����Ʀb�@�_ 
	A[0] = (double*) malloc(N*N*sizeof(double)) ; 
	for ( i = 1 ; i<N ; ++i )
	{
	    A[i] = A[ i-1] +N ; 
	}
	*/ 
>>>>>>> origin/C14011073
	
	tic = clock();
	for(i=0;i<N;++i)
	{
		x[i] = cos(i*M_PI/N);
		printf("%f\n",x[i]);
	}
	
	for(i=0;i<N;++i)
	{
		for(j=0;j<N;++j)
		{
			A[i][j] = 1.0/(i+j+1);
			printf("%f\t",A[i][j]);
			if(j%5 == 4) printf("\n");
		}
	}
<<<<<<< HEAD
	printf("\n");
=======
	/* b = A*x
		b[0] = A[0][0]*x[0]+A[0][1]x[1]+...+A[0][N-1]*x[N-1]
		...
		general form 
		b[i] = A[i][0]*x[0]+A[i][1]x[1]+...+A[i][N-1]*x[N-1]
		b[N-1] = A[N-1][0]*x[0]+A[N-1][1]x[1]+...+A[N-1][N-1]*x[N-1]
		--> b[i] = 0.0 ; 
		
	*/
>>>>>>> origin/C14011073
	for(i=0;i<N;++i)
	{
		b[i] = 0.0;
		for(j=0;j<N;++j)
		{
			b[i] = b[i] + A[i][j]*x[j];
		}
		printf("%f\n",b[i]);
	}
	toc = clock();
	printf("computational time: %f seconds\n",1.0*(toc-tic)/CLOCKS_PER_SEC);
	#if DEBUG
	for(i=0;i<N;++i)
	{
		printf("b[%d]=%f\n",i,b[i]);
	}
	#endif
	
	system("Pause");
	return 1;
}
