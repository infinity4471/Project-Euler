#include <cstdio>
#include <algorithm>

#define N 50

using namespace std;

// 0 -> black
// 1 -> red

int main( void )
{
	long long dp[ N + 1 ][ 2 ];
	dp[ 0 ][ 0 ] = 1;
	dp[ 0 ][ 1 ] = 0;
	for( int i = 1; i <= N; i++ ) {
		dp[ i ][ 0 ] = dp[ i - 1 ][ 0 ] + dp[ i - 1 ][  1 ];
		dp[ i ][ 1 ] = 0;
		for( int j = i - 3; j >= 0; j-- ) {
			dp[ i ][ 1 ] += dp[ j ][ 0 ];
		}
	}
	printf("%lld\n", dp[ N ][ 0 ] + dp[ N ][ 1 ] );
	return 0;
} 
