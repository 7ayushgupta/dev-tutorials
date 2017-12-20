#include <stdio.h>

string[] gray(string n1[], string n2[], int m)
{
  int val = (int) (pow(2, m-1));
  for(int i=0; i<val; i++)
    n2[i]='0' + n1[i];
  for(int i=0; i<val; i++)
    n2[i+val] = '1' + n1[val-i];
  if(m==2)
    n2 = {"00","01","11","10"};
    return n2;
  return gray(n2, n1, m-1);
}
//logic for the gray code, but will needed to be implemented using a char 2D array.
//JAVA :P :')
