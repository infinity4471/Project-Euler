#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void)
{
	//freopen("input.in","rt",stdin);
	long long matrix[80][80];
	long long dp[80][80];
	for(int i=0; i<5; i++)
		for(int j=0; j<5; j++)
			scanf("%d",&matrix[i][j]);
	for(int i=0; i<5; i++)
	{
		for(int j=0; j<5; j++)
		{
			if(i==0 && j==0)
				dp[i][j]=matrix[i][j];
			else if(j==0 && i)
				dp[i][j]=dp[i-1][j]+matrix[i][j];
			else if(i==0 && j)
				dp[i][j]=dp[i][j-1]+matrix[i][j];
			else if(i && j)
				dp[i][j]=min(dp[i][j-1],dp[i-1][j])+matrix[i][j];
			//printf("%lld\n",dp[i][j]);
		}
	}
	printf("%lld\n",dp[4][4]);
	return 0;
}
