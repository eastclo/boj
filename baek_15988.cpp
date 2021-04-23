#include <bits/stdc++.h>

using namespace std;
#define ll long long

const int MN = 1010101;
const int MOD = 1e9+9;

ll dp[MN];
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int T;	cin >> T;
	dp[0] = 1; dp[1] = 1; dp[2] = 2;
	for(int i = 3; i < MN; i++)
		dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]) % MOD;

	while(T--) {
		int N;	cin >> N;
		cout << dp[N] % MOD << '\n';
	}
}
