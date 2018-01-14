#include <stdio.h>
#include <stdlib.h>

void read_mat(int m, int n, int *A)
{
	int i,j;
	for(i=0; i<m;i++)
	{
		for(j=0; j<n; j++)
			scanf("%d", (A + n*i +j);
		scanf("\n");
	}
}

void print_mat(int m, int n, int *A)
{
	int i,j;
	for (i = 0; i<m; i++)
	{	for(j=0; j<n; j++)
			printf("%d", *(A+n*i+j);
		printf("\n");
		}
}

void add_mat(int m, int n, int *A, int *B, int *C)
{
	int i,j;
	for(i=0; i<m;i++)
		for (j=0;j<n;j++)
			*(C+n*i+j)=*(A+n*i+j)+*(B+n*i+j);
}











int main()
{
	int p, q;
	scanf("%d", &p, &q);
	int A* = (int *) malloc(m*n*sizeof(int));
	int B* = (int *) malloc(m*n*sizeof(int));
	int C* = (int *) malloc(m*n*sizeof(int));

	read_mat(m,n,A);
	read_mat(m,n,B);
	add_mat(m,n,A,B,C);
	print_mat(m,n,C);
	
	return 0;
}

