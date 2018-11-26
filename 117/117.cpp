#include <cstdio>

#define N 50

typedef unsigned long long llu;

// 0 -> black
// 1 -> red
// 2 -> green
// 3 -> blue

int main( void )
{
	llu dp[ N + 1 ][ 4 ];
	dp[ 0 ][ 0 ] = 1;
	dp[ 0 ][ 1 ] = 0;
	dp[ 0 ][ 2 ] = 0;
	dp[ 0 ][ 3 ] = 0;
	for( int i = 1; i <= N; i++ ) {
		dp[ i ][ 0 ] = dp[ i - 1 ][ 0 ] + dp[ i - 1 ][ 1 ] + dp[ i - 1 ][ 2 ] + dp[ i - 1 ][ 3 ];
		dp[ i ][ 1 ] = ( i - 2 >= 0 ? ( dp[ i - 2 ][ 0 ] + dp[ i - 2 ][ 1 ] + dp[ i - 2 ][ 2 ] + dp[ i - 2 ][ 3 ] ) : 0 );
		dp[ i ][ 2 ] = ( i - 3 >= 0 ? ( dp[ i - 3 ][ 0 ] + dp[ i - 3 ][ 1 ] + dp[ i - 3 ][ 2 ] + dp[ i - 3 ][ 3 ] ) : 0 );
		dp[ i ][ 3 ] = ( i - 4 >= 0 ? ( dp[ i - 4 ][ 0 ] + dp[ i - 4 ][ 1 ] + dp[ i - 4 ][ 2 ] + dp[ i - 4 ][ 3 ] ) : 0 );
	}
	printf("%llu\n", dp[ N ][ 0 ] + dp[ N ][ 1 ] + dp[ N ][ 2 ] + dp[ N ][ 3 ] );
	return 0;
}
