#include <iostream>

#define N 100

using namespace std;

bool isleap(int year)
{
	if(year%100==0 && year%400)
		return false;
	if(year%4)
		return false;
	return true;
}

int main(void)
{
	int ext=0;
	int cnt=0;
	int months[2][12]={ {31,28,31,30,31,30,31,31,30,31,30,31} , { 31,29,31,30,31,30,31,31,30,31,30,31} } ;
	for(int i=1; i<N; i++ ) {
		int p;
		if(isleap(i+1900)) p=1;
		else p=0;
		for(int j=0; j<12; j++) {
			int mod;
			for(int k=0; k<months[p][j]; k++,ext++) {
				mod=ext%7;
				if(k==0 && mod==6)
					cnt++;
			}
		}
	}
	cout << cnt << endl;
	return false;
}
