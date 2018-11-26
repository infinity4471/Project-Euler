#include <cstdio>

int main(void)
{
	int max=0,maxpos=0;
	for(int i=1; i<=1000; i++)
	{
		int d=1,basmod,mod=0,cnt=0,n=i;
		while(d<i) d*=10;
		basmod=d%n;
		d=d%n;
		while(mod!=basmod)
		{
			cnt++;
			while(d<n) d*=10;
			mod=d%n;
			if(mod==0) break;
			d=d%n;
			if(cnt>max*100)
			{
				cnt=1;
				break;	
			}
		}
		if(cnt>max)
		{
			max=cnt;
			maxpos=i;
		}
	}
	printf("%d %d\n",maxpos,max);
	return 0;
}
