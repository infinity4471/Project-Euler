#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main(void)
{
	char stringa[]="0123456789";
	for(int i=1; i<1000000; i++)
	{
		next_permutation(stringa,stringa+10);
	}
	printf("%s\n",stringa);
	return 0;
}
