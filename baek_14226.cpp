#include <bits/stdc++.h>

using namespace std;

const int MN = 2010;
const int INF = 1e9;

int dp[MN][MN];
int main(void)
{
	ios::sync_with_stdio(false);    cin.tie(NULL);
	int N;  cin >> N;
	fill(&dp[0][0], &dp[MN-1][MN], INF);

	dp[0][1] = 0;
	for(int i = 0; i < MN; i++) {
		for(int j = 0; j < MN; j++)
			dp[i][i] = min(dp[i][i], dp[j][i] + 1);
		for(int j = i+1; j < MN; j++)
			dp[i][j] = min(dp[i][j], dp[i][j-i] + 1);
		for(int j = 0; j+1 < MN; j++)
			dp[i][j] = min(dp[i][j], dp[i][j+1] + 1);
		for(int j = i+1; j < MN; j++)
			dp[i][j] = min(dp[i][j], dp[i][j-i] + 1);
		for(int j = 0; j+1 < MN; j++)
			dp[i][j] = min(dp[i][j], dp[i][j+1] + 1);
	}

	int res = INF;
	for(int i = 0; i < MN; i++)
		res = min(res, dp[i][N]);
	cout << res;
}
