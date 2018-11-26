#include <cstdio>

int factorial(int num)
{
	if(num==1 || num==0)
		return 1;
	else return num*factorial(num-1);
}
int dig_fact(int number)
{
	int sum=0;
	while(number>0)
	{
		sum+=factorial(number%10);
		number/=10;
	}
	return sum;
}
int main(void)
{
	int sum=0;
	for(int i=3; i<1000000; i++)
	{
		if(dig_fact(i)==i)
		{
			sum+=i;
			printf("%d\n", i);
		}
	}
	printf("%d\n", sum);
	return 0;
}
