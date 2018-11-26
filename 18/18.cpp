#include <cstdio>

const int N=15;
const int M=15;
int max(0);
int tree[N+1][M+1];

void traverse(int sum,int x,int y)
{
	if(tree[x][y]!=0)
	{
		sum+=tree[x][y];
		traverse(sum,x+1,y+1);
		traverse(sum,x+1,y);
	}
	if(sum>max)
	{
		max=sum;
	}
}
int main(void)
{
	FILE * pfile=fopen("triangle.in","r");
	int prev=0;
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<prev+1; j++)
		{
			fscanf(pfile,"%d",&tree[i][j]);
		}
		fscanf(pfile,"\n");
		prev++;
	}
	fclose(pfile);
	traverse(0,0,0);
	pfile=fopen("triangle.out","w");
	fprintf(pfile,"%d\n", max);
	fclose(pfile);
	return 0;
}
