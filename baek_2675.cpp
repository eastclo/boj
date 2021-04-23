#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int T;	cin >> T;
	while(T--) {
		int R; string s; cin >> R >> s;
		for(char a : s) {
			for(int i = 0; i < R; i++)
				cout << a;
		}
		cout << '\n';
	}
}
