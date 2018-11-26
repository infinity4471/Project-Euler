#include <cstdio>
#include <algorithm>
#include <vector>

#define STATE 15000100
#define MAXN 16
#define N 8

using namespace std;

vector< int > valid;
int C[ 2 ][ STATE ];

int get_bit( int mystring, int i ) {
  for( int j = 0; j < i; j++ ) mystring /= 3;
  return mystring % 3;
}

int get_size( int mystring ) {
  int size = 0;
  while( mystring ) {
    mystring /= 3;
    size++;
  }
  return size;
}

bool is_valid( int mystring ) {
  int prev = mystring % 3;
  mystring /= 3;
  while( mystring ) {
    if( mystring % 3 == prev ) return false;
    mystring /= 3;
  }
  return true;
}

void produce() {
  for( int i = 0; i < 14348907; i++ ) {
    if( is_valid( i ) ) valid.pb( i );
  }
}

int main( void ) {
  C[ 0 ][ 0 ] = 1;
  C[ 0 ][ 1 ] = 1;
  C[ 0 ][ 2 ] = 1;
  for( int i = 1; i < MAXN; i++ ) {
    int total = valid.size();
    for( int j = 0; j < total; j++ ) {

    }
  }
  return 0;
}
