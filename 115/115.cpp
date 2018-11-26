#include <cstdio>
#include <algorithm>

#define N 200
#define M 50

using namespace std;

// 0 -> black
// 1 -> red

int main( void )
{
	long long dp[ N + 1 ][ 2 ];
	dp[ 0 ][ 0 ] = 1;
	dp[ 0 ][ 1 ] = 0;
	for( int i = 1;; i++ ) {
		dp[ i ][ 0 ] = dp[ i - 1 ][ 0 ] + dp[ i - 1 ][  1 ];
		dp[ i ][ 1 ] = 0;
		for( int j = i - M; j >= 0; j-- ) {
			dp[ i ][ 1 ] += dp[ j ][ 0 ];
		}
		if( dp[ i ][ 0 ] + dp[ i ][ 1 ] > 1000000 ) {
			printf("%d\n", i );
			break;
		}
	}
	return 0;
} 
