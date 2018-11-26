#include <cstdio>
#include <string>
#include <map>
#include <cmath>

#define N 8
#define K 3

using namespace std;

typedef long long ll;
typedef pair< int, string > pis;

string kth( int state )
{
	string knary;
	while( state > 0 ) {
		knary += ( state % K + '0' );
		state /= K;
	}
	return knary;
}

bool valid( string a, string b )
{
	for( int i = 0; i < a.length(); i++ ) {
		if( a[ i ] == b[ i ] ) {
			return false;
		}
	}
	return true;
}

int main( void )
{
	map< pis, ll > dp;
	ll ans = 0;
	for( int i = 0; i < K; i++ ) {
		string a;
		a += i + '0';
		dp[ make_pair( 1, a ) ] = 1;
	}
	for( int i = 2; i <= N; i++ ) {
		for( int j = 0; j < pow( K, i ); j++ ) {
			string a = kth( j ), c;
			for( int k = a.length(); k < i; k++ ) {
				a += '0';
			}
			dp[ make_pair( i, a ) ] = 0;
			for( int z = 0; z < pow( K, i - 1 ); z++ ) {
				string compar = kth( z );
				bool status = true;
				for( int k = compar.length(); k < i - 1; k++ ) {
					compar += '0';
				}
				for( int k = 0; k < i - 1; k++ ) {
					if( compar[ k ] == a[ k ] || compar[ k ] == a[ k + 1 ] ) {
						status = false;
						break;
					}
				}
				if( !status ) {
					continue;
				}
				for( int k = 0; k < pow( K, i - 1 ); k++ ) {
					string b = kth( k );
					for( int l = b.length(); l < i - 1; l++ ) {
						b += '0';
					}
					string newa,newb = b;
					newa = compar;
					if( valid( newa, newb ) ) {
						dp[ make_pair( i, a ) ] += dp[ make_pair( i - 1, newb ) ];
					}
				}
			}
		}
	}
	for( int i = 0; i < pow( K, N ); i++ ) {
		string a = kth( i );
		for( int k = a.length(); k < N; k++ ) {
			a += '0';
		}
		ans += dp[ make_pair( N, a ) ];
	}
	printf("%lld\n", ans );
	return 0;
}
// answer = 10834893628237824
