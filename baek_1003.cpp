#include <bits/stdc++.h>

using namespace std;
const int MN = 41;

int dp0[MN], dp1[MN];
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	dp0[0] = 1;
	dp1[1] = 1;
	for(int i = 2; i <= 40; i++) {
		dp0[i] = dp0[i-1] + dp0[i-2];
		dp1[i] = dp1[i-1] + dp1[i-2];
	}

	int T;	cin >> T;
	while(T--) {
		int N;	cin >> N;
		cout << dp0[N] << ' ' << dp1[N] << '\n';
	}
}
