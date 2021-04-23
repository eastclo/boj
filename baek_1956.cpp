#include <bits/stdc++.h>

using namespace std;

const int MN = 401;
const int INF = 1e9;

int dp[MN][MN];
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	fill(&dp[0][0], &dp[MN-1][MN], INF);
	int N, M;	cin >> N >> M;
	for(int i = 0; i < M; i++) {
		int u, v, w;	cin >> u >> v >> w;
		dp[u][v] = min(dp[u][v], w);
	}
	for(int i = 1; i <= N; i++)
		dp[i][i] = 0;

	for(int k = 1; k <= N; k++)
		for(int i = 1; i <= N; i++)
			for(int j = 1; j <= N; j++)
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);

	int res = INF;
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			if(i == j) continue;
			res = min(res, dp[i][j] + dp[j][i]);
		}
	}

	if(res == INF)
		cout << -1;
	else
		cout << res;
}
