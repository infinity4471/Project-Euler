#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int total = 0;
  for(int i=0; i<1000; i++) {
    if(!(i%3) || !(i%5))
      total+=i;
  }
  printf("%d\n", total);
  return 0;
}
