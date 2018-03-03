#include "stdio.h"

int main(int argc, char const *argv[]) {
  long long int sum1 = 0, sum2 = 0;
  int i;
  for(i=1;i<=100;i++)
  {
    sum1 += i*i;
    sum2 += i;
  }

  printf("%lld\n",sum2*sum2 - sum1);

  return 0;
}
