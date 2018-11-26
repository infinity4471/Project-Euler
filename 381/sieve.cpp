#include <cstdio>
#include <algorithm>

#define MAXN 1000100

using namespace std;

int div[ MAXN + 1 ];

int main( void ) {
  int A, B;
  scanf("%d%d", &A, &B );
  for( int i = 1; i <= MAXN; i++ ) div[ i ] = 1; ;
  for( int i = 2; i <= MAXN; i++ ) {
    for( int j = i; j <= MAXN; j += i) {
      div[ j ]++;
    }
  }
  for( int i = A; i <= B; i++ ) {
    printf("%d\n", div[ i ] );
  }
  return 0;
}
