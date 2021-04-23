#include <bits/stdc++.h>

using namespace std;

int S, N;
int main(void)
{
	ios::sync_with_stdio(false);    cin.tie(NULL);
	cin >> N;
	for(int i = 0; i < N; i++) {
		string s;   cin >> s;
		if(s == "all") {
			S = -1; continue;
		}
		else if(s == "empty") {
			S = 0; continue;
		}
		int a;  cin >> a;
		if(s == "add")
			S |= (1 << a);
		else if(s == "remove") 
			S &= ~(1 << a);
		else if(s == "toggle") 
			S ^= (1 << a);
		else if(S & (1 << a))
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}
}
