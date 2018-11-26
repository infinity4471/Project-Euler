#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

ll gcd( ll a, ll b ) {
    if( !a || !b ) return a + b;
    return !b ? a: gcd( b, a % b );
}

ll lcm( ll a, ll b ) {
    return ( ll ) a * b / gcd( a, b );
}

int main( void ) {
    ll ans = 1;
    for( int i = 1; i <= 20; i++ ) ans = lcm( ans, i );
    printf("%lld\n", ans );
}
