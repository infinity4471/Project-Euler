#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

#define N 20
#define F 1700
#define MOD 1000000000

int main( void )
{
	long long C[ N + 1 ][ F + 1 ], dp[ N + 1 ][ F + 1 ], ans = 0;
	memset( C, 0, sizeof( C ) );
	memset( dp, 0, sizeof( dp ) );
	for( int i = 1; i < 10; i++ ) {
		C[ 1 ][ i*i ] = 1;
		dp[ 1 ][ i*i ] = i;
	}
	for( int i = 2; i <= N; i++ ) {
		for( int j = 0; j <= F; j++ ) {
			for( int k = 0; k*k <= j && k < 10; k++ ) {
				C[ i ][ j ] += C[ i - 1 ][ j - ( k*k ) ] % MOD;
				C[ i ][ j ] %= MOD;
				dp[ i ][ j ] += ( 10*dp[ i - 1 ][ j - ( k*k ) ] % MOD ) + ( C[ i - 1 ][ j - ( k*k ) ]*k % MOD );
				dp[ i ][ j ] %= MOD;
			}
		}
	}
	for( int i = 1; i <= N; i++ ) {
		for( int j = 1; j <= sqrt( F ); j++ ) {
			ans += dp[ i ][ j * j ];
			ans %= MOD;
		}
	}
	printf("%lld\n", ans );
	return 0;
}
