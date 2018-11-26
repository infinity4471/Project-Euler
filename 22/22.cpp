#include <cstdio>
#include <cstring>

int score(char name[])
{
	int a=0;
	for(int i=0; i<strlen(name); i++)
		a+=name[i]-'A'+1;
	return a;
}
int main(void)
{
	freopen("names2.txt","rt",stdin);
	char name[20];
	int totscore=0;
	for(int i=1; i<=5163; i++)
	{
		scanf("%s",&name);
		totscore+=score(name)*i;
	}
	printf("%d\n",totscore);
	return 0;
}
