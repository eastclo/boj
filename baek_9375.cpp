#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int T;	cin >> T;
	while(T--) {
		map<string,int> clo;
		int N;	cin >> N;
		for(int i = 0; i < N; i++) {
			string a, b;	cin >> a >> b;
			clo[b]++;
		}
		int res = 1;
		for(auto it : clo)
			res *= (it.second + 1);

		cout << res-1 << '\n';
	}
}
