#include "stdio.h"

int main(int argc, char const *argv[]) {

  long a,b,c;
  long long int sum = 2;

  a = 1;
  b = 2;
  c = a + b;
  while(c<4000000)
  {
    c = a + b;
    if(c%2==0)
      sum+=c;
    a = b;
    b = c;
  }

  printf("%lld %ld\n",sum, a );

  return 0;
}
