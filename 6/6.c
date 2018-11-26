#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
  int N=100;
  double pow1=(N*(N+1))/2,pow2=0;
  for(int i=0; i<=100; i++)
    pow2+=pow(i,2);
  printf("%.0f\n", pow(pow1,2)-pow2);
  return 0;
}
