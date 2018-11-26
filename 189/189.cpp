#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <cmath>

#define N 2

using namespace std;

typedef long long ll;
typedef pair< int, string > pis;

string tern( int state )
{
	string ternary;
	while( state > 0 ) {
		ternary += ( state % 3 + '0' );
		state /= 3;
	}
	return ternary;
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

bool correct( string a )
{
	for( int i = 0; i < a.length() - 1; i++ ) {
		if( a[ i ] == a[ i + 1 ] ) {
			return false;
		}
	}
	return true;
}

int main( void )
{
	map< pis, ll > dp;
	ll ans = 0;
	dp[ make_pair( 1, "0") ] = 1;
	dp[ make_pair( 1, "1" ) ] = 1;
	dp[ make_pair( 1, "2" ) ] = 1; // base cases
	for( int i = 2; i <= N; i++ ) {
		printf("row %d\n", i );
		for( int j = 0; j < pow( 3, 2*i - 1 ); j++ ) {
			string a = tern( j );
			for( int k = a.length(); k < 2*i - 1; k++ ) {
				a += '0';
			}
			dp[ make_pair( i, a ) ] = 0;
			if( !correct( a ) ) {
				continue;
			}
			for( int k = 0; k < pow( 3, 2*i - 3 ); k++ ) {
				string b = tern( k );
				for( int l = b.length(); l < 2*i - 3; l++ ) {
					b += '0';
				}
				if( !correct( b ) ) {
					continue;
				}
				string newa,newb;
				for( int l = 0; l < a.length(); l++ ) {
					if( l % 2 ) newa += a[ l ];
				} 
				for( int l = 0; l < b.length(); l++ ) {
					if( l % 2 == 0 ) newb += b[ l ];
				}
				if( valid( newa, newb ) ) {
					cout << "state1 -> " << a << endl;
					cout << "state2 -> " << b << endl << endl;
					dp[ make_pair( i, a ) ] += dp[ make_pair( i - 1, b ) ];
				}
			}
		}
	}
	for( int i = 0; i < pow( 3, 2*N - 1 ) - 1; i++ ) {
		string a = tern( i );
		for( int k = a.length(); k < 2*N - 1; k++ ) {
			a += '0';
		}
		ans += dp[ make_pair( N, a ) ];
	}
	printf("%lld\n", ans );
	return 0;
}
