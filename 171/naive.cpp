#include <cstdio>
#include <cstring>
#include <cmath>

#define N 2

long produce( int num )
{
	long result = 0;
	while( num > 0 ) {
		result += ( num % 10 ) * ( num % 10 );
		num /= 10;
	}
	return result;
}

int main( void )
{
	bool is[ 1000001 ];
	long ans = 0;
	memset( is, 0, sizeof( is ) );
	for( int i = 1; i <= 1000; i++ ) {
		is[ i*i ] = true;
	}
	for( int i = 0; i < pow( 10, N ); i++ ) {
		printf("i -> %d\n", i );
		if( is[ produce( i ) ] ) {
			ans += i;
		}
	}
	printf("%ld\n", ans );
}
