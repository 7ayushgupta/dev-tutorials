#include <stdio.h>

int rec(int n)
{
  if (n==4) return 1;
  return (rec(n-1)+n-3);
}
int main()
{
  printf("%d", rec(6));
}
