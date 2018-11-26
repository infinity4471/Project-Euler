#include <cstdio>
#include <algorithm>

#define MOD 1000000
#define MAXN 1100

using namespace std;

int dp[ MAXN + 1 ][ MAXN + 1 ];

int main( void ) {
  for( int i = 1; i <= MAXN; i++ ) dp[ i ][ 1 ] = 1;
  for( int i = 2; i <= 10; i++ ) {
    int val = 1;
    for( int j = 2; j <= i; j++ ) {
      dp[ i ][ j ] = dp[ i - 1 ][ j - 1 ];
      if( i > j ) dp[ i ][ j ] = ( dp[ i ][ j ] + dp[ i - j ][ min( j ] ) % MOD;
      val = ( val + dp[ i ][ j ] ) % MOD;
    }
    printf("solution for %d -> %d\n", i, val );
    if( val == 0 ) {
      printf("%d\n", i );
      break;
    }
  }
  return 0;
}
