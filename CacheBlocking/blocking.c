#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#define N 2048
#define B 256

int min(int a, int b)
{
	if(a < b )
		return a;
	return b;

}

int main(int argc, char **argv)
{



  struct timeval start, end;

  srand (100);
  int random_number;
  int *x[N];
  int *z[N];
  int *y[N];
  

  int i, j, k, ii, jj, kk;

  for (i = 0; i < N; i++)
  {
         x[i] = (int *)malloc(N * sizeof(int));
	 z[i] = (int *)malloc(N * sizeof(int));
	 y[i] = (int *)malloc(N * sizeof(int));
  }

  for(i = 0; i < N; i++)
  {
	for(j = 0; j < N; j++)
	{
		random_number = rand()%100;
		z[i][j] = random_number;
		random_number = rand()%100;
		y[i][j] = random_number;
	}
  }
	
  gettimeofday(&start, NULL);

  int r;
  for(jj = 0; jj < N; jj = jj + B)
	for(kk = 0; kk < N; kk = kk + B)
		for(i = 0; i < N; i++)
			for(j = jj; j < min(jj + B, N); j = j + 1)
			{
				r = 0;
				for(k = kk; k < min(kk + B, N); k++)
				{
					r = r + y[i][k]*z[k][j];
				}
				x[i][j] = x[i][j] + r;
			}

  gettimeofday(&end, NULL);

  printf("%ld\n", ((end.tv_sec * 1000000 + end.tv_usec)
		  - (start.tv_sec * 1000000 + start.tv_usec)));

  return 0;
}
