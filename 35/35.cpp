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

bool circ(int i)
{
	int log=0;
	int k=i;
	while(k>0)
	{
		k/=10;
		log++;
	}
	for(int j=0; j<log; j++)
	{
		int t=i%10;
		t*=pow(10,log);
		i+=t;
		i/=10;
		if(!primes[i])
			return false;
	}
	return true;
}

int main(void)
{
	init();
	ceive();
	int cnt=0;
	circ(197);
	for(int i=2; i<N; i++)
	{
		if(circ(i))
		{
			printf("%d\n",i);
			cnt++;
		}
	}
	printf("%d\n",cnt);
	return 0;
}
