#include <cstdio>
#include <cstring>

int sumi(char word[],int N)
{
	int cnt=0,sum=0;
	while(cnt<N)
	{
		sum+=word[cnt]-'A'+1;
		cnt++;
	}
	return sum;
}
int main(void)
{
	freopen("words.txt","rt",stdin);
	bool triangle[1000001];
	for(int i=0; i<=1000000; i++)
		triangle[i]=false;
	char word[20];
	int num=0;
	for(int i=1; i<1000; i++)
		triangle[i*(i+1)/2]=true;
	for(int i=0; i<=1786; i++)
	{
		scanf("%s",&word);
		if(triangle[sumi(word,strlen(word))])
			num++;
	}
	printf("H lysh einai auth ----> %d\n",num);
	return 0;
}
