#include <cstdio>
#include <algorithm>
#include <vector>

#define X first
#define Y second
#define mp make_pair
#define pb push_back

using namespace std;

typedef unsigned long long ll;
typedef pair< ll, ll > pii;

const ll N = 100000000LLU;

pii extended_euclidean( ll a, ll b ) {
  if( b == 0LL ) return mp( 1LL, 0LL );
  pii A = extended_euclidean( b, a % b );
  return mp( A.Y, ( A.X - A.Y * ( a / b ) ) );
}

ll inverse( ll a, ll p ) {
  return ( extended_euclidean( a, p ).X + p ) % p;
}

ll S( ll P ) {
  ll smod = P - 1, total = P - 1;
  for( int k = 2; k <= 5; k++ ) {
    ll modinv = inverse( P - k + 1, P );
    smod = ( smod * modinv ) % P;
    total = ( total + smod ) % P;
  }
  return total;
}

ll ans = 0LLU;
vector< ll > PRIMES;

int main( void ) {
  for( ll i = 2LLU; i < N; i++ ) {
    bool status = false;
    for( int j = 0; j < PRIMES.size() && PRIMES[ j ] * PRIMES[ j ] <= i; j++ ) {
      if( i % PRIMES[ j ] == 0 ) {
        status = true;
        break;
      }
    }
    if( !status ) {
      printf("adding -> %llu\n", i );
      PRIMES.pb( i );
    }
  }
  printf("done with primes!\n");
  for( int i = 2; i < PRIMES.size(); i++ ) {
    if( i % 1000 == 0 ) printf("%0.3lf\n", 100.0 * ( double )i / ( double )PRIMES.size() );
    ans += S( PRIMES[ i ] );
  }
  printf("%llu\n", ans );
  return 0;
}
