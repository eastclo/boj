#include <bits/stdc++.h>

using namespace std;
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	string s;	cin >> s;
	int sum = 0;
	for(char a : s) {
		if(a < 'S') sum += (a - 'A') / 3 + 3;
		else if(a == 'S') sum += 8;
		else if(a < 'W') sum += 9;
		else sum += 10;
	}
	cout << sum;
}
