#include <stdio.h>
#include <math.h>

int is_pyth(int a,int b,int c) {
  if(pow((double)a,2)+pow((double)b,2)==pow((double)c,2))
    return 1;
  else return 0;
}
int main()
{
  for(int a=0; a<500; a++) {
    for(int b=0; b<a; b++) {
      for(int c=0; c<b; c++) {
	if(c+b+a==1000 && is_pyth(c,b,a)) {
	  printf("%d\n", a*b*c);
	  return 0;
	}
      }
    }
  }
}
