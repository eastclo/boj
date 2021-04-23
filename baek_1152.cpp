#include <bits/stdc++.h>

using namespace std;

const int MN = 1;
const int INF = 1e9;

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	string s;
	getline(cin, s);
	int ch = 0;
	if(s[0] == ' ') ch++;
	if(s.back() == ' ') ch++;
	int num = 0;
	for(char a : s)
		if(a == ' ')
			num++;

	cout << num - ch + 1;
}
