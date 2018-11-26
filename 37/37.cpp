#include <cstdio>
#include <cmath>

#define N 1000000

bool primes[N];
void init()
{
	for(int i=2; i<N; i++)
		primes[i]=true;
}

void ceive()
{
	for(int i=2; i<N; i++)
		for(int j=2*i; j<N; j+=i)
			if(j%i==0)
				primes[j]=false;
}

int log(int i)
{
	int lg=0;
	while(i>0)
	{
		i/=10;
		lg++;
	}
	return lg;
}

bool r2l(int i)
{
	while(i>0)
	{
		if(!primes[i])
			return false;
		i/=10;
	}
	return true;
}

bool l2r(int i)
{
	while(i>0)
	{
		if(!primes[i])
			return false;
		int dig=i/pow(10,log(i)-1);
		i-=dig*pow(10,log(i)-1);
	}
	return true;
}

int main(void)
{
	init();
	ceive();
	long sum=0;
	for(int i=10; i<1000000; i++)
	{
		if(l2r(i) && r2l(i))
		{
			printf("%d\n",i);
			sum+=i;
		}
	}
	printf("%d\n",sum);
	return 0;
}
