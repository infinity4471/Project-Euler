#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

int main(void)
{
	ifstream name("names.txt");
	ofstream name2("names2.txt");
	string names[5163];
	for(int i=0; i<5163; i++)
		name >> names[i];
	sort(names,names+5163);
	for(int i=0; i<5163; i++)
		name2 << names[i] << endl;
	return 0;
}
