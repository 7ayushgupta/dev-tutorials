#include <stdio.h>
#include <stdlib.h>

void rank(int* X, int s, int m)
{
	int c = s;
	while(s--)
		if(*(X+s)>m)
			c--;
	printf("%d",c);
}

int main()
{
	int a;
	a = scanf("%d\n");
	int A* = (int *) malloc(a*sizeof(int));
	for (int i = 0; i<a; i++)
		scanf("%d");
	scanf("\n");
	int m = scanf("%d\n");
	rank(A, a, m);
}
