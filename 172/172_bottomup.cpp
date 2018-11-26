#include <cstdio>
#include <algorithm>
#include <cstring>

#define N 18

using namespace std;

typedef long long ll;

static ll dp[ N + 1 ][ 10 ][ 4 ][ 4 ][ 4 ][ 4 ][ 4 ][ 4 ][ 4 ][ 4 ][ 4 ][ 4 ];

int main( void )
{
	ll ans = 0;
	memset( dp, 0, sizeof( dp ) );
	dp[ 1] [ 0 ][ 1 ][ 0 ][ 0 ][ 0 ][ 0 ][ 0 ][ 0 ][ 0 ][ 0 ][ 0 ] = 0;
	dp[ 1 ][ 1 ][ 0 ][ 1 ][ 0 ][ 0 ][ 0 ][ 0 ][ 0 ][ 0 ][ 0 ][ 0 ] = 1;
	dp[ 1 ][ 2 ][ 0 ][ 0 ][ 1 ][ 0 ][ 0 ][ 0 ][ 0 ][ 0 ][ 0 ][ 0 ] = 1;
	dp[ 1 ][ 3 ][ 0 ][ 0 ][ 0 ][ 1 ][ 0 ][ 0 ][ 0 ][ 0 ][ 0 ][ 0 ] = 1;
	dp[ 1 ][ 4 ][ 0 ][ 0 ][ 0 ][ 0 ][ 1 ][ 0 ][ 0 ][ 0 ][ 0 ][ 0 ] = 1;
	dp[ 1 ][ 5 ][ 0 ][ 0 ][ 0 ][ 0 ][ 0 ][ 1 ][ 0 ][ 0 ][ 0 ][ 0 ] = 1;
	dp[ 1 ][ 6 ][ 0 ][ 0 ][ 0 ][ 0 ][ 0 ][ 0 ][ 1 ][ 0 ][ 0 ][ 0 ] = 1;
	dp[ 1 ][ 7 ][ 0 ][ 0 ][ 0 ][ 0 ][ 0 ][ 0 ][ 0 ][ 1 ][ 0 ][ 0 ] = 1;
	dp[ 1 ][ 8 ][ 0 ][ 0 ][ 0 ][ 0 ][ 0 ][ 0 ][ 0 ][ 0 ][ 1 ][ 0 ] = 1;
	dp[ 1 ][ 9 ][ 0 ][ 0 ][ 0 ][ 0 ][ 0 ][ 0 ][ 0 ][ 0 ][ 0 ][ 1 ] = 1;
	for( int k = 2; k <= N; k++ ) {
		for( int l = 0; l < 10; l++ ) {
			for( int a = 0; a <= 3; a++ ) {
			for( int b = 0; b <= 3; b++ ) {
			for( int c = 0; c <= 3; c++ ) {
			for( int d = 0; d <= 3; d++ ) {
			for( int e = 0; e <= 3; e++ ) {
			for( int f = 0; f <= 3; f++ ) {
			for( int g = 0; g <= 3; g++ ) {
			for( int h = 0; h <= 3; h++ ) {
			for( int i = 0; i <= 3; i++ ) {
			for( int j = 0; j <= 3; j++ ) {
				if( !a && !b && !c && !d && !e && !f && !g && !h && !i && !j ) {
					continue;
				}
				else if( ( l == 0 && !a ) || 
					 ( l == 1 && !b ) ||
					 ( l == 2 && !c ) ||
					 ( l == 3 && !d ) ||
					 ( l == 4 && !e ) ||
					 ( l == 5 && !f ) ||
					 ( l == 6 && !g ) ||
					 ( l == 7 && !h ) ||
					 ( l == 8 && !i ) ||
					 ( l == 9 && !j ) ) {
						continue;
				}
				int na = a, nb = b, nc = c, nd = d, ne = e, nf = f, ng = g, nh = h, ni = i, nj = j;
				if( l == 0 ) na--;
				else if( l == 1 ) nb--;
				else if( l == 2 ) nc--;
				else if( l == 3 ) nd--;
				else if( l == 4 ) ne--;
				else if( l == 5 ) nf--;
				else if( l == 6 ) ng--;
				else if( l == 7 ) nh--;
				else if( l == 8 ) ni--;
				else if( l == 9 ) nj--;
				dp[ k ][ l ][ a ][ b ][ c ][ d ][ e ][ f ][ g ][ h ][ i ][ j ] =
				dp[ k - 1 ][ 0 ][ na ][ nb ][ nc ][ nd ][ ne ][ nf ][ ng ][ nh ][ ni ][ nj ] +
				dp[ k - 1 ][ 1 ][ na ][ nb ][ nc ][ nd ][ ne ][ nf ][ ng ][ nh ][ ni ][ nj ] +
				dp[ k - 1 ][ 2 ][ na ][ nb ][ nc ][ nd ][ ne ][ nf ][ ng ][ nh ][ ni ][ nj ] +
				dp[ k - 1 ][ 3 ][ na ][ nb ][ nc ][ nd ][ ne ][ nf ][ ng ][ nh ][ ni ][ nj ] +
				dp[ k - 1 ][ 4 ][ na ][ nb ][ nc ][ nd ][ ne ][ nf ][ ng ][ nh ][ ni ][ nj ] +
				dp[ k - 1 ][ 5 ][ na ][ nb ][ nc ][ nd ][ ne ][ nf ][ ng ][ nh ][ ni ][ nj ] +
				dp[ k - 1 ][ 6 ][ na ][ nb ][ nc ][ nd ][ ne ][ nf ][ ng ][ nh ][ ni ][ nj ] +
				dp[ k - 1 ][ 7 ][ na ][ nb ][ nc ][ nd ][ ne ][ nf ][ ng ][ nh ][ ni ][ nj ] +
				dp[ k - 1 ][ 8 ][ na ][ nb ][ nc ][ nd ][ ne ][ nf ][ ng ][ nh ][ ni ][ nj ] +
				dp[ k - 1 ][ 9 ][ na ][ nb ][ nc ][ nd ][ ne ][ nf ][ ng ][ nh ][ ni ][ nj ];
			}
			}
			}
			}
			}
			}
			}
			}
			}
			}
		}
	} 
	for( int k = 0; k < 10; k++ ) {
		for( int a = 0; a <= 3; a++ ) {
		for( int b = 0; b <= 3; b++ ) {
		for( int c = 0; c <= 3; c++ ) {
		for( int d = 0; d <= 3; d++ ) {
		for( int e = 0; e <= 3; e++ ) {
		for( int f = 0; f <= 3; f++ ) {
		for( int g = 0; g <= 3; g++ ) {
		for( int h = 0; h <= 3; h++ ) {
		for( int i = 0; i <= 3; i++ ) {
		for( int j = 0; j <= 3; j++ ) {
			ans += dp[ N ][ k ][ a ][ b ][ c ][ d ][ e ][ f ][ g ][ h ][ i ][ j ];
		}
		}
		}
		}
		}
		}
		}
		}
		}
		}
	}
	printf("%lld\n", ans );
	return 0;
}
