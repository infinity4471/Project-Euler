#include <cstdio>

int main(void)
{
	int max=0;
	long long number=600851475143LL;
	bool primes[775121];
	for(int i=2; i<775121; i++)
		primes[i]=true;
	for(int i=2; i<775121; i++)
	{
		for(int j=2*i; j<775121; j+=i)
		{
			if(j%i==0)
			{
				primes[j]=false;
			}
		}
		//printf("%d\n", i);
	}
	for(int i=775121; i>=2; i--)
	{
		if(number%i==0 && primes[i]==true)
		{
			number/=i;
			max=i;
			break;
		}
	}
	printf("%d\n", max);
	return 0;
}
