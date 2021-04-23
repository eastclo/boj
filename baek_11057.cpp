#include <bits/stdc++.h>

using namespace std;

const int MOD = 10007;

int dp[2][10];
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N;	cin >> N;
	fill(dp[0], dp[0]+10, 1);
	for(int n = 1; n < N; n++) {
		for(int i = 0; i < 10; i++) 
			dp[n%2][i] = 0;
		for(int i = 0; i < 10; i++) {
			for(int j = i; j < 10; j++) 
				dp[n%2][j] += dp[(n-1)%2][i] % MOD;
		}
	}

	int res = 0;
	for(int i = 0; i < 10; i++) 
		res += dp[(N-1)%2][i] % MOD;
	cout << res % MOD;
}
