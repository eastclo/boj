#include <bits/stdc++.h>

using namespace std;
#define ll long long

const int MN = 100101;
const int MOD = 1e9+9;

ll dp[MN][4];
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	dp[1][1] = 1;
	dp[2][2] = 1;
	dp[3][3] = 1, dp[3][1] = 1, dp[3][2] = 1;
	for(int i = 4; i < MN; i++) {
		dp[i][1] = (dp[i-1][2] + dp[i-1][3]) % MOD;
		dp[i][2] = (dp[i-2][1] + dp[i-2][3]) % MOD;
		dp[i][3] = (dp[i-3][1] + dp[i-3][2]) % MOD;
	}

	int T;	cin >> T;
	while(T--) {
		int N;	cin >> N;
		cout << (dp[N][1] + dp[N][2] + dp[N][3]) % MOD<< '\n';
	}
}
