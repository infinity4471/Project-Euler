#include <cstdio>
#include <cstring>

int main(void)
{
	freopen("num.in","rt",stdin);
	char a[50];
	for(int i=0; i<100; i++)
	{
		scanf("%s",&a);
		printf("%s",a);
		if(i<99) printf("+");
	}
	printf("\n");
	return 0;
}
