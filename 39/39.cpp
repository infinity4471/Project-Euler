#include <cstdio>
#include <cmath>

int pyth(int a,int b,int c)
{
	if(pow(a,2)+pow(b,2)==pow(c,2))
		return 1;
	return 0;
}
int main(void)
{
	int solutions[1001];
	int max=0;
	int maxim=0;
	for(int i=0; i<1001; i++)
		solutions[i]=0;
	for(int i=1; i<=400; i++)
	{
		for(int j=i+1; j<=400; j++)
		{
			for(int k=j+1; k<=400; k++)
			{
				if(pyth(i,j,k) && i+j+k<=1000)
				{
					solutions[i+j+k]++;
				}
			}
		}
	}
	for(int i=0; i<=1000; i++)
	{
		if(solutions[i]>max)
		{
			maxim=i;
			max=solutions[i];
		}
	}
	printf("%d %d\n",max,maxim);
	return 0;
}
