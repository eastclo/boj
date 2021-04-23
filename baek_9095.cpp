#include <bits/stdc++.h>

using namespace std;

const int MN = 12;

int dp[MN];
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for(int i = 4; i < MN; i++)
		dp[i] = dp[i-1] + dp[i-2] + dp[i-3];

	int T;	cin >> T;
	while(T--) {
		int a;	cin >> a;
		cout << dp[a] << '\n';
	}
}
