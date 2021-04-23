#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	string s;	cin >> s;
	map<char,char> m;
	m['E'] = 'I'; m['I'] = 'E'; m['S'] = 'N'; m['N'] = 'S';
	m['T'] = 'F'; m['F'] = 'T'; m['P'] = 'J'; m['J'] = 'P';
	for(char a : s) 
		cout << m[a];
}
