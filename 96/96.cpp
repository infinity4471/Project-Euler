#include <iostream>
#include <functional>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
#include <map>

using namespace std;

struct sudoku {
	string game[9];
};

queue<sudoku> q;

bool isvalid(sudoku sud)
{
	bool status=true;
	for(int i=0; i<9; i++) {
		bool used[10];
		for(int j=0; j<=9; j++)
			used[j]=false;
		for(int j=i; j<9; j++) {
			if(sud.game[i][j]=='0' || sud.game[j][i]=='0')
				continue;
			if(used[sud.game[i][j]-'0'] || used[sud.game[j][i]-'0'])
				status=false;
			used[sud.game[i][j]-'0']=1;
			used[sud.game[j][i]-'0']=1;
		}
	}
	for(int i=0; i<9; i+=3) {
		for(int j=i; j<9; j+=3) {
			bool used[10];
			for(int k=0; k<10; k++)
				used[k]=false;
			for(int k=i; k<=i+2; k++) {
				for(int l=j; l<=j+2; l++) {
					if(sud.game[k][l]=='0')
						continue;
					if(used[sud.game[k][l]-'0'])
						status=false;
					used[sud.game[k][l]-'0']=true;
				}
			}
		}
	}
	return status;
}

int main(void)
{
	sudoku s;
	for(int i=0; i<9; i++)
		cin >> s.game[i];
	cout << isvalid(s) << endl;
	return 0;
}
