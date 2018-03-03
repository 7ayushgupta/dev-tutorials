#include "stdio.h"

int isPrime(int n)
{
  if(n%3==0)
    return 0;
  for(int i=5;i*i<=n;i+=6)
  {
    if(n%i==0 || n%(i+2)==0)
      return 0;
  }
  return 1;
}

int main(int argc, char const *argv[]) {

  int count = 2;

  for(int i=5; ;i+=2)
  {
    if(isPrime(i))
      count++;
    if(count==10001)
    {
      printf("%d\n",i);
      return 0;
    }
    /if(count%100==0)
      printf("Found prime number %d\n",count);
  }

  return 0;
}
