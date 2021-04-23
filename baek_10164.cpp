#include <bits/stdc++.h>

using namespace std;

const int MN = 16;

int dp[MN][MN], res1, res2;
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N, M, K;	cin >> N >> M >> K;
	if(!K) {
		dp[1][1] = 1;
		for(int i = 1; i <= N; i++) 
			for(int j = 1; j <= M; j++) 
				dp[i][j] += dp[i-1][j] + dp[i][j-1];

		cout << dp[N][M];
		return 0;
	}

	int x = K / M + 1;
	int y = K % M;
	if(y == 0) {
		x--, y = M;
	}

	dp[1][1] = 1;
	for(int i = 1; i <= x; i++) 
		for(int j = 1; j <= y; j++) 
			dp[i][j] += dp[i-1][j] + dp[i][j-1];
	res1 = dp[x][y];
	memset(dp, 0, sizeof(dp));
	dp[x][y] = 1;
	for(int i = x; i <= N; i++) 
		for(int j = y; j <= M; j++) 
			dp[i][j] += dp[i-1][j] + dp[i][j-1];
	res2 = dp[N][M];

	cout << res1 * res2;
}
