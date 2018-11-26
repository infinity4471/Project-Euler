#include <cstdio>

int is_pal(int num)     
{
	int n_rev = num,rev = 0,i;
	while(num > 0)
	{
		i = num % 10;
		rev = rev * 10 + i;
		num /= 10;
	}
	if(n_rev == rev)
		return 1;
	return 0;
}
int main(void)
{
	int max=0;
	for(int i=100; i<999; i++)
	{
		for(int j=i+1; j<999; j++)
		{
			if(is_pal(i*j) && i*j>max)
			{
				max=i*j;
			}
		}
	}
	printf("%d\n", max);
}
