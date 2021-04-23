#include <bits/stdc++.h>

using namespace std;
const int MN = 101;
const int MOD = 1e9;

long long dp[2][10];
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N;	cin >> N;
	for(int i = 1; i < 10; i++) 
		dp[0][i] = 1;

	for(int i = 1; i < N; i++) {
		fill(dp[i%2], dp[i%2] + 10, 0);
		for(int j = 1; j < 9; j++) {
			dp[i%2][j-1] += dp[(i-1)%2][j] % MOD;
			dp[i%2][j+1] += dp[(i-1)%2][j] % MOD;
		}
		dp[i%2][1] += dp[(i-1)%2][0] % MOD;
		dp[i%2][8] += dp[(i-1)%2][9] % MOD;
	}
	long long res = 0;
	for(int i = 0; i < 10; i++) 
		res += dp[(N-1)%2][i];

	cout << res % MOD;
}
