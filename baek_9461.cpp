#include <bits/stdc++.h>

using namespace std;
const int MN = 101;

long long dp[MN];
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	dp[1] = 1; dp[2] = 1; dp[3] = 1; dp[4] = 2; dp[5] = 2;
	for(int i = 6; i < MN; i++)
		dp[i] = dp[i-1] + dp[i-5];

	int T;	cin >> T;
	while(T--) {
		int N;	cin >> N;
		cout << dp[N] << '\n';
	}
}
