#include <stdio.h>

int is_prime(int inum)
{
  for(int icounter=2; icounter<inum; icounter++){
    if(!(inum%icounter))
      return 0;
  }
  return 1;
}
int main(void)
{
  int prime=2;
  for(int i=1; i<=10001; prime++) {
    if(is_prime(prime))
      i++;
  }
  printf("%d\n", prime-1);
  return 0;
}
