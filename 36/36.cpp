#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

string tostr(int num,int base)
{
	string number;
	stack<char> s;
	while(num > 0) {
		s.push(num%base+'0');
		num/=base;
	}
	while(!s.empty() ) {
		number+=s.top();
		s.pop();
	}
	return number;
}

bool palin(string a)
{
	bool status=true;
	stack<char> s;
	queue<char> q;
	for(int i=0; i<a.length(); i++) {
		s.push(a[i]);
		q.push(a[i]);
	}
	while(!s.empty()) {
		if(s.top()!=q.front())
			status=false;
		s.pop();
		q.pop();
	}
	return status;
}

int main(void)
{
	int ans=0;
	for(int i=0; i<1000000; i++) {
		if(palin(tostr(i,10)) && palin(tostr(i,2)))
			ans+=i;
	}
	cout << ans << endl;
	return 0;
}
