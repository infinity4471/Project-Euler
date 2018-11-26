#include <cstdio>
#include <algorithm>

#define N 20

using namespace std;

int main(void)
{
	unsigned long long dp[N+1][N+1]; // max number of ways to move from one corner to i,j
	dp[0][0]=1;
	for(int i=1; i<=N; i++)
		dp[i][0]=dp[0][i]=1;
	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=N; j++)
		{
			dp[i][j]=dp[i-1][j]+dp[i][j-1];
			//printf("%llu ",dp[i][j]);
		}
		//printf("\n");
	}
	printf("%llu\n",dp[N][N]);
	return 0;
}
