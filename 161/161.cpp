#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>

#define N 12
#define M 9

#define X first
#define Y second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair< pair< pair< int, int >, pair< int, int > >, int > state;

map<state, ll > memo;

ll dp( int i, int j, int bit1, int bit2, int bit3 )
{
	ll& ans = memo[ mp( mp( mp( i, j ), mp( bit1, bit2 ) ), bit3 ) ];
	if( ans ) return ans;
	if( i == N ) return ans = ( bit1 == 0 && bit2 == 0 && bit3 == 0 );
	if( j == M ) return ans = dp( i + 1, 0, bit2, bit3, 0 );
	if( bit1 & ( 1 << j ) ) return ans = dp( i, j + 1, bit1, bit2, bit3 );	
	ans = 0;
	ll ret = 0;
	for( int n = 0; n <= 5; n++ ) {
		if( n == 0 ) {
			if( j + 3 <= M && !( bit1 & ( 1 << j ) ) && !( bit1 & ( 1 << ( j + 1 ) ) ) && !( bit1 & ( 1 << ( j + 2 ) ) ) ) {
				ret += dp( i, j + 3, bit1, bit2, bit3 );
			}
		}
		else if( n == 1 ) {
			if( i + 3 <= N && !( bit1 & ( 1 << j ) ) && !( bit2 & ( 1 << j ) ) && !( bit3 & ( 1 << j ) ) ) {
				ret += dp( i, j + 1, bit1, bit2 | ( 1 << j ), bit3 | ( 1 << j ) );
			}
		}
		else if( n == 2 ) {
			if( j + 2 <= M && !( bit1 & ( 1 << j ) ) && !( bit1 & ( 1 << ( j + 1 ) ) ) && !( bit2 & ( 1 << j ) ) ) {
				ret += dp( i, j + 2, bit1, bit2 | ( 1 << j ), bit3 );
			}
		}
		else if( n == 3 ) {
			if( j + 2 <= M && !( bit1 & ( 1 << j ) ) && !( bit2 & ( 1 << j ) ) && !( bit2 & ( 1 << ( j + 1 ) ) ) ) {
				int newbit2 = bit2;
				newbit2 |= ( 1 << j );
				newbit2 |= ( 1 << ( j + 1 ) );
				ret += dp( i, j + 1, bit1, newbit2, bit3 );
			}
		}
		else if( n == 4 ) {
			if( j > 0 && !( bit1 & ( 1 << j ) ) && !( bit2 & ( 1 << j ) ) && !( bit2 & ( 1 << ( j - 1 ) ) ) ) {
				int newbit2 = bit2;
				newbit2 |= 1 << j;
				newbit2 |= 1 << ( j - 1 );
				ret += dp( i, j + 1, bit1, newbit2, bit3 );
			}
		}
		else if( n == 5 ) {
			if( j + 2 <= M && !( bit1 & ( 1 << j ) ) && !( bit1 & ( 1 << ( j + 1 ) ) ) && !( bit2 & ( 1 << ( j + 1 ) ) ) ) {
				ret += dp( i, j + 2, bit1, bit2 | ( 1 << ( j + 1 ) ), bit3 );
			}
		}
	}
	return ans = ret;
}

int main( void )
{
	printf("answer for grid %dx%d -> %lld\n", N, M, dp( 0, 0, 0, 0, 0 ) );
	return 0;
}
