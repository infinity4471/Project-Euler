#include <cstdio>

long long dp[ 201 ];

int main(void)
{
	int A[]={0,1,2,5,10,20,50,100,200};
	dp[ 0 ] = 1;
	for( int i = 1; i <= 8; i++ ) {
		for( int j = A[ i ]; j <= 200; j++ ) {
			dp[ j ] += dp[ j - A[ i ] ];
		}
	}
	printf("%lld\n",dp[C]);
	return 0;
}
