#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

void add(char a[],char b[],char c[])
{
	vector<char> v;
	int rem=0;
	for(int i=strlen(b)-1,j=strlen(c)-1; i>=0 && j>=0; i--,j--) {
		v.push_back(((b[i]-'0'+c[j]-'0'+rem)%10)+'0');
		rem=(b[i]-'0'+c[j]-'0')/10;
	}
	if(strlen(b)>strlen(c)) {
		for(int i=strlen(c)-strlen(b)-1; i>=0; i--)
			v.push_back(((b[i]-'0'+rem)%10)+'0');
	} 
	else if(strlen(c)>strlen(b)) {
		for(int i=strlen(c)-strlen(b)-1; i>=0; i--) {
			v.push_back(((c[i]-'0'+rem)%10)+'0');
		}
	}
	if(rem!=0 && strlen(b)==strlen(c))
		v.push_back(rem+'0');
	for(int i=v.size()-1,j=0; i>=0; i--,j++)
		a[j]=v[i];
}

int main(void)
{
	char a[6000][1000];
	scanf("%s%s%s",&a[1],&a[2],&a[3]);
	for(int i=4; ; i++ ) {
		add(a[i],a[(i-2)],a[(i-1)]);
		printf("%s\n",a[i]);
		if(strlen(a[i])==10) {
			printf("%d\n",i);
			break;
		}
	}
	return 0;
}
