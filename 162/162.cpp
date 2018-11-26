#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long ll;

const int MAXL = 16;

int len;
ll memo[ MAXL + 1 ][ MAXL + 1 ][ MAXL + 1 ][ MAXL + 1 ];

ll dp( int n, int zeros, int ones, int as )
{
	ll& ret = memo[ n ][ zeros ][ ones ][ as ];
	if( ret != -1 ) return ret;
	if( n == len ) {
		if( zeros > 0 && ones > 0 && as > 0 ) return ret = 1;
		else return ret = 0;
	}
	
	ret = 0;
	ret = dp( n + 1, zeros, ones + 1, as ) + dp( n + 1, zeros, ones, as + 1 ) + 13*dp( n + 1, zeros, ones, as );
	if( n > 0 ) ret += dp( n + 1, zeros + 1, ones, as );
	return ret;
}

int main( void )
{
	ll ans = 0;
	len = MAXL;
	do {
		memset( memo, -1, sizeof( memo ) );
		ans += dp( 0, 0, 0, 0 );
		len--;
	} while( len > 0 );
	printf("%lld\n", ans );
	return 0;
}	
