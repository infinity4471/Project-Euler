#include <cstdio>
#include <algorithm>
#include <cstring>

#define MAXL 20
#define BASE 10

using namespace std;

typedef long long ll;

ll memo[ MAXL + 1 ][ BASE + 1 ][ BASE + 1 ][ BASE + 1 ];

ll dp( int n, int one, int two, int three )
{
	ll& ret = memo[ n ][ one ][ two ][ three ];
	if( ret != -1 ) return ret;
	if( one + two + three > 9 ) return ret = 0;
	if( n == MAXL ) return ret = 1;
	ret = 0;
	for( int i = 0; i < BASE; i++ ) {
		if( n == 0 && i == 0 ) continue;
		ret += dp( n + 1, two, three, i );
	}
	return ret;
}

int main( void )
{
	memset( memo, -1, sizeof( memo ) );
	printf("%lld\n", dp( 0, 0, 0, 0 ) );
	return 0;
}
