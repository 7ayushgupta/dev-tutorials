#include <stdio.h>

int main(int argc, char const *argv[]) {
  long number = 1;

  for(int i=2;i<=20;i++)
  {
      if(number%i!=0)
      {
        for(int j=2;j<=i;j++)
        {
          if(i%j==0)
          {
            if((number*j)%i==0)
            {
              number *= j;
              break;
            }
          }
        }
      }
  }

  printf("%ld\n",number);

  return 0;
}
