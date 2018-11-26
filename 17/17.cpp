#include <iostream>
#include <string>
#include <algorithm>

#define N 1000

using namespace std;

string mon[]={"one","two","three","four","five","six","seven","eight","nine"};
string special[]={"eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
string deca[]={"ten","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
const string hou="hundred";
const string th="thousand";

string tostr(int p)
{
	string num;
	if(p>=1000) {
        	num+=mon[p/1000-1];
                num+=th;
                p=p%1000;
	}
	if(p>=100) {
		num+=mon[p/100-1];
		num+=hou;
		p=p%100;
		if(p!=0) num+="and";
	}
	if(p>=20) {
                num+=deca[p/10-1];
                p=p%10;
        }
	if(p>10 && p<20) {
		num+=special[p%11];
		p=0;
	}
	if(p==10) { p=0; num+="ten"; }
	if(p>0 && p<10) {
		num+=mon[p-1];
	}
	return num;
}

int main(void)
{
	int ans=0;
	for(int i=1; i<=N; i++) {
		ans+=tostr(i).length();
	}
	cout << ans << endl;
	return 0;
}
