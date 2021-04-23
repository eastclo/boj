#include <iostream>

using namespace std;

int dp[1001][1001];

int solve(int n, int k){
	if(dp[n][k] != 0)
		return dp[n][k];
	if(k == 0 || k == n)
		return 1;

	return dp[n][k] = (solve(n-1, k-1) + solve(n-1, k)) % 10007;
}

int main(void) {
	int N, K;       cin >> N >> K;

	dp[0][0] = 1;
	dp[1][0] = 1;
	dp[1][1] = 1;

	cout << solve(N,K) << '\n';
}
