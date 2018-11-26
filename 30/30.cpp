#include <cstdio>
#include <cmath>

int digsum(int a)
{
	int dig,num=0;
	while(a>0)
	{
		dig=a%10;
		num+=pow(dig,5);
		a/=10;
	}
	return num;
}
int main(void)
{
	int sum=0;
	for(int i=2; i<1000000; i++)
	{
		printf("%d\n",i);
		if(digsum(i)==i)
			sum+=i;
	}
	printf("%d\n",sum);
	return 0;
}
