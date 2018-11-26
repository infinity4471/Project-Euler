#include <cstdio>

#define N 50

typedef long long unsigned llu;

int main( void )
{
	llu dp[ N + 1 ][ 2 ], ans = 0;
	dp[ 0 ][ 0 ] = 1;
	dp[ 0 ][ 1 ] = 0;
	dp[ 1 ][ 0 ] = 1;
	dp[ 1 ][ 1 ] = 0;
	for( int i = 2; i <= N; i++ ) {
		dp[ i ][ 0 ] = dp[ i - 1 ][ 0 ] + dp[ i - 1 ][ 1 ];
		dp[ i ][ 1 ] = dp[ i - 2 ][ 0 ] + dp[ i - 2 ][ 1 ];
	}
	ans += dp[ N ][ 0 ] + dp[ N ][ 1 ] - 1;
	dp[ 0 ][ 0 ] = 1;
	dp[ 0 ][ 1 ] = 0;
	dp[ 1 ][ 0 ] = 1;
	dp[ 1 ][ 1 ] = 0;
	dp[ 2 ][ 0 ] = 1;
	dp[ 2 ][ 1 ] = 0;
	for( int i = 3; i <= N; i++ ) {
		dp[ i ][ 0 ] = dp[ i - 1 ][ 0 ] + dp[ i - 1 ][ 1 ];
		dp[ i ][ 1 ] = dp[ i - 3 ][ 0 ] + dp[ i - 3 ][ 1 ];
	}
	ans += dp[ N ][ 0 ] + dp[ N ][ 1 ] - 1;
	dp[ 0 ][ 0 ] = 1;
	dp[ 0 ][ 1 ] = 0;
	dp[ 1 ][ 0 ] = 1;
	dp[ 1 ][ 1 ] = 0;
	dp[ 2 ][ 0 ] = 1;
	dp[ 2 ][ 1 ] = 0;
	dp[ 3 ][ 0 ] = 1;
	dp[ 3 ][ 1 ] = 0;
	for( int i = 4; i <= N; i++ ) {
		dp[ i ][ 0 ] = dp[ i - 1 ][ 0 ] + dp[ i - 1 ][ 1 ];
		dp[ i ][ 1 ] = dp[ i - 4 ][ 0 ] + dp[ i - 4 ][ 1 ];
	}
	ans += dp[ N ][ 0 ] + dp[ N ][ 1 ] - 1;
	printf("%lld\n", ans );
	return 0;
}
