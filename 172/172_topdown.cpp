#include <cstdio>
#include <algorithm>
#include <cstring>

#define N 18

using namespace std;

typedef long long ll;

static ll memo[ N + 1 ][ 10 ][ 4 ][ 4 ][ 4 ][ 4 ][ 4 ][ 4 ][ 4 ][ 4 ][ 4 ][ 4 ];

ll C( int idx, int n, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j )
{
	if( a > 3 || b > 3 || c > 3 || d > 3 || e > 3 || f > 3 || g > 3 || h > 3 || i > 3 || j > 3 ) {
		return memo[ idx ][ n ][ a ][ b ][ c ][ d ][ e ][ f ][ g ][ h ][ i ][ j ] = 0;
	}
	if( memo[ idx ][ n ][ a ][ b ][ c ][ d ][ e ][ f ][ g ][ h ][ i ][ j ] != -1 ) {
		return memo[ idx ][ n ][ a ][ b ][ c ][ d ][ e ][ f ][ g ][ h ][ i ][ j ];
	}
	if( idx == N ) {
		return memo[ idx ][ n ][ a ][ b ][ c ][ d ][ e ][ f ][ g ][ h ][ i ][ j ] = 1;
	}
	return ( memo[ idx ][ n ][ a ][ b ][ c ][ d ][ e ][ f ][ g ][ h ][ i ][ j ] =
	C( idx + 1, 0, a + 1, b, c, d, e, f, g, h, i, j ) +
	C( idx + 1, 1, a, b + 1, c, d, e, f, g, h, i, j ) +
	C( idx + 1, 2, a, b, c + 1, d, e, f, g, h, i, j ) +
	C( idx + 1, 3, a, b, c, d + 1, e, f, g, h, i, j ) +
	C( idx + 1, 4, a, b, c, d, e + 1, f, g, h, i, j ) +
	C( idx + 1, 5, a, b, c, d, e, f + 1, g, h, i, j ) +
	C( idx + 1, 6, a, b, c, d, e, f, g + 1, h, i, j ) +
	C( idx + 1, 7, a, b, c, d, e, f, g, h + 1, i, j ) +
	C( idx + 1, 8, a, b, c, d, e, f, g, h, i + 1, j ) +
	C( idx + 1, 9, a, b, c, d, e, f, g, h, i, j + 1 ) );
}

int main( void )
{
	ll ans = 0;
	memset( memo, -1, sizeof( memo ) );
	ans = 
	C( 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 ) +
	C( 1, 2, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 ) +
	C( 1, 3, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 ) +
	C( 1, 4, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 ) +
	C( 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 ) +
	C( 1, 6, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 ) +
	C( 1, 7, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 ) +
	C( 1, 8, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 ) +
	C( 1, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 );
	printf("%lld\n", ans );
	return 0;
}
