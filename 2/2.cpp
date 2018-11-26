#include <cstdio>
#include <vector>

using namespace std;

int main(void)
{
	vector<int> fib;
	int sum=0;
	fib.push_back(0);
	fib.push_back(1);
	for(int i=2; fib.at(i-1)<=4000000; i++)
	{
		fib.push_back(fib.at(i-1)+fib.at(i-2));
	}
	for(int i=0; i<fib.size(); i++)
	{
		if(fib.at(i)%2==0)
			sum+=fib.at(i);
	}
	printf("%d\n", sum);
	return 0;
}
