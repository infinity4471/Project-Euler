#include <cstdio>
#include <algorithm>
#include <cassert>

#define N 1000
#define PSEUDO 500500
#define MOD ( 1 << 20 )
#define INF 112233445566778899

using namespace std;

long long parsum[ N + 1 ][ N + 1 ],  A[ PSEUDO + 1 ], tri[ N + 1 ][ N + 1 ];

int main( void )
{
	long long ans = INF, t = 0;
	for( int i = 1; i <= PSEUDO; i++ ) {
		t = 615949*t % MOD + 797807 % MOD;
		A[ i ] = ( t % MOD ) - ( 1 << 19 );
	}
	t = 1;
	for( int i = 1; i <= N; i++ ) {
		for( int j = 1; j <= i; j++ ) {
			tri[ i ][ j ] = A[ t++ ];
		}
	}
	for( int i = 1; i <= N; i++ ) {
		parsum[ i ][ 0 ] = 0;
		for( int j = 1; j <= i; j++ ) {
			parsum[ i ][ j ] = parsum[ i ][ j - 1 ] + tri[ i ][ j ];
		}
	}
	for( int i = 1; i <= N; i++ ) {
		for( int j = 1; j <= i; j++ ) {
			long long sum = tri[ i ][ j ], cell = j;
			ans = min( ans, sum );
			for( int k = i + 1; k <= N; k++ ) {
				if( cell + 1 > k ) {
					break;
				}
				int diff = k - i + 1;
				sum += parsum[ k ][ cell + 1 ] - parsum[ k ][ cell + 1 - diff ];
				cell++;
				ans = min( ans, sum );
			}
		}
	}
	printf("%lld\n", ans );
	return 0;
}
