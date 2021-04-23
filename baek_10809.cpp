#include <bits/stdc++.h>

using namespace std;


int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	string a;	cin >> a;
	char st = 'a';
	for(int i = 0; i < 26; i++) {
		int res = a.find(string(1, st+i));	
		if(res > a.size())
			cout << -1 << ' ';
		else
			cout << res << ' ';
	}
}
