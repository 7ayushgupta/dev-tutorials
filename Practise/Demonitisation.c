#include <stdio.h>
int denomination(int m, int i, int d[], int n)
{
    if(m==0)
        return 1;
    if(m<0)
        return 0;
    if(i>=n)
        return 0;
    return denomination(m, i+1, d, n) + denomination(m-d[i], i, d, n);
}
int main()
{
    int a[3]={2,3,5};
	printf("%d", denomination(10, 0, a,3));
	return 0;
}
