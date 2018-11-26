#include <cstdio>

int main(void)
{
	bool primes[2000000];
	long long sum=0;
	for(int i=0; i<2000000; i++)
		primes[i]=true;
	for(int i=2; i<2000000; i++)
	{
		for(int j=2*i; j<2000000; j+=i)
		{
			if(j%i==0)
			{
				primes[j]=false;
			}
		}
		//printf("%d\n", i);
	}
	for(int i=2; i<2000000; i++)
	{
		if(primes[i]==true)
		{
			sum+=i;
		}
	}
	printf("%lld\n", sum);
	return 0;
}
