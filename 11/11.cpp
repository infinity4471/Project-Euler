#include <cstdio>

#define K 20

int g[K][K];

int hor(int i,int j)
{
	int a=g[i][j];
	for(int k=j+1; k<j+4; k++)
		a*=g[i][k];
	return a;
}

int rec(int i,int j)
{
	int a=g[i][j];
	for(int k=i+1; k<i+4; k++)
		a*=g[k][j];
	return a;
}

int diag(int i,int j)
{
	int a=g[i][j];
	int b=a;
	for(int k=i+1,l=j+1; k<i+4 && l<j+4; k++,l++)
		a*=g[k][l];
	for(int k=i+1,l=j-1; k<i+4 && l>=0; k++,l--)
		b*=g[k][l];
	if(b>a) a=b;

	return a;
}

int main(void)
{
	int max=0;
	for(int i=0; i<K; i++)
		for(int j=0; j<K; j++)
			scanf("%2d",&g[i][j]);
	for(int i=0; i<K-4; i++)
	{
		for(int j=0; j<K-4; j++)
		{
			int a,b,c;
			a=rec(i,j);
			b=hor(i,j);
			c=diag(i,j);
			if(a>max)
				max=a;
			if(b>max)
				max=b;
			if(c>max)
				max=c;
		}
	}
	printf("%d\n",max);
	return 0;
}
