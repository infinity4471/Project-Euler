#include <cstdio>
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <string>

#define N 3
#define M 3

using namespace std;

typedef pair< int, int > pii;
typedef long long ll;

map< string, bool > used;
vector< string > solu;

void init( map< pii, bool >& state )
{
	for( int i = -10; i <= N + 10; i++ ) {
		for( int j = -10; j <= M + 10; j++ ) {
			if( 1 <= i && i <= N && 1 <= j && j <= M ) {
				state[ make_pair( i, j ) ] = false;
			} else {
				state[ make_pair( i, j ) ] = true;
			}
		}
	}
}

pii feasible( map< pii, bool > state, int col, int type )
{
	pii myp = make_pair( -1, -1 );
	int j = col;
	for( int i = 1; i <= N; i++ ) {
		if( type == 1 ) {
			if( i <= 2 ) {
				continue;
			}
			if( !state[ make_pair( i, j ) ] && !state[ make_pair( i - 1, j ) ] && !state[ make_pair( i - 2, j ) ] ) {
				myp = make_pair( i, j );
			} else {
				return myp;
			}
		}
		else if( type == 2 ) {
			if( !state[ make_pair( i, j ) ] && !state[ make_pair( i, j + 1 ) ] && !state[ make_pair( i, j + 2 ) ] ) {
				myp = make_pair( i, j );
			} else {
				return myp;
			}
		}
		else if( type == 3 ) {
			if( i == 1 ) {
				continue;	
			}
			if( !state[ make_pair( i, j ) ] && !state[ make_pair( i - 1, j ) ] && !state[ make_pair( i - 1, j + 1 ) ] ) {
				myp = make_pair( i, j );
			} else {
				return myp;
			}
		}
		else if( type == 4 ) {
			if( i == 1 ) {
				continue;
			}
			if( !state[ make_pair( i, j ) ] && !state[ make_pair( i - 1, j ) ] && !state[ make_pair( i, j - 1 ) ] ) {
				myp = make_pair( i, j );
			} else {
				return myp;
			}
		}
		else if( type == 5 ) {
			if( i == 1 ) {
				continue;
			}
			if( !state[ make_pair( i, j ) ] && !state[ make_pair( i - 1, j ) ] && !state[ make_pair( i - 1, j - 1 ) ] ) {
				myp = make_pair( i, j );
			} else {
				return myp;
			}
		}
		else if( type == 6 ) {
			if( i == 1 ) {
				continue;
			}
			if( !state[ make_pair( i, j ) ] && !state[ make_pair( i, j + 1 ) ] && !state[ make_pair( i - 1, j ) ] ) {
				myp = make_pair( i, j );
			} else {
				return myp;
			}
		}
	}
	return myp;
}

bool solved( map< pii, bool > state )
{
	for( int i = 1; i <= N; i++ ) {
		for( int j = 1; j <= M; j++ ) {
			if( !state[ make_pair( i, j ) ] ) {
				return false;
			}
		}
	}
	return true;
}

ll solve( map< pii, bool > state, string solution, pii start, int type )
{
	ll ans = 0;
	if( type > 0 ) {
		int i = start.first, j = start.second;
		if( type == 1 ) {
			state[ make_pair( i, j ) ] = true;
			state[ make_pair( i - 1, j ) ] = true;
			state[ make_pair( i - 2, j ) ] = true;
		}
		else if( type == 2 ) {
			state[ make_pair( i, j ) ] = true;
			state[ make_pair( i, j + 1 ) ] = true;
			state[ make_pair( i, j + 2 ) ] = true;
		}
		else if( type == 3 ) {
			state[ make_pair( i, j ) ] = true;
			state[ make_pair( i - 1, j ) ] = true;
			state[ make_pair( i - 1, j + 1 ) ] = true;
		}
		else if( type == 4 ) {
			state[ make_pair( i, j ) ] = true;
			state[ make_pair( i, j - 1 ) ] = true;
			state[ make_pair( i - 1, j ) ] = true;
		}
		else if( type == 5 ) {
			state[ make_pair( i, j ) ] = true;
			state[ make_pair( i - 1, j ) ] = true;
			state[ make_pair( i - 1, j - 1 ) ] = true;
		}
		else if( type == 6 ) {
			state[ make_pair( i, j ) ] = true;
			state[ make_pair( i - 1, j ) ] = true;
			state[ make_pair( i, j + 1 ) ] = true;
		}
	}
	if( solved( state ) ) {
		if( !used[ solution ] ) {
			used[ solution ] = true;
			solu.push_back( solution );
			return 1;
		} else {
			return 0;
		}
	}
	for( int i = 1; i <= M; i++ ) {
		for( int j = 1; j <= 6; j++ ) {
			pii sol = feasible( state, i, j );
			if( sol.first != -1 && sol.second != -1 ) {
				ans += solve( state, solution + ( char )( j + '0' ), sol, j );
			}
		}
	}
	return ans;
}

int main( void )
{
	map< pii, bool > start;
	init( start );
	printf("evaluating number of solutions:");
	printf(" %lld\n", solve( start, "", make_pair( -1, -1 ), 0 ) );
	printf("solutions: \n");
	for( int i = 0; i < solu.size(); i++ ) {
		cout << solu[ i ] << endl;
	}
	return 0;
}
