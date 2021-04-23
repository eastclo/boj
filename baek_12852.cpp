#include <bits/stdc++.h>

using namespace std;

const int MN = 1e6+1;
const int INF = 1e9;

int dp[MN];
int par[MN];
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N;	cin >> N;
	if(N == 1) {
		cout << 0 << '\n' << 1;
		return 0;
	}
	fill(dp, dp + N + 1, INF);
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	for(int i = 4; i <= N; i++) {
		if(i%3 == 0 && dp[i] > dp[i/3] + 1) {
			par[i] = i/3;
			dp[i] = dp[i/3] + 1;
		}
		if(i%2 == 0 && dp[i] > dp[i/2] + 1) {
			par[i] = i/2;
			dp[i] = dp[i/2] + 1;
		}
		if(dp[i] > dp[i-1] + 1) {
			par[i] = i-1;
			dp[i] = dp[i-1] + 1;
		}
	}

	cout << dp[N] << '\n';
	for(int prev = N; prev != 0; prev = par[prev]) 
		cout << prev << ' ';
	cout << 1;
}
