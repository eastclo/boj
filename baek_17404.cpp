#include <bits/stdc++.h>

using namespace std;

const int MN = 1010;
const int INF = 1e9;

int dp[MN][3][3];
int w[MN][3];
int main(void)
{
	ios::sync_with_stdio(false);    cin.tie(NULL);
	int N;  cin >> N;
	for(int i = 1; i <= N; i++)
		cin >> w[i][0] >> w[i][1] >> w[i][2];

	dp[1][0][0] = w[1][0]; dp[1][0][1] = INF; dp[1][0][2] = INF;
	dp[1][1][1] = w[1][1]; dp[1][1][0] = INF; dp[1][1][2] = INF;
	dp[1][2][2] = w[1][2]; dp[1][2][0] = INF; dp[1][2][1] = INF;
	for(int i = 2; i < N; i++) {
		for(int j = 0; j < 3; j++) {
			dp[i][j][0] = min(dp[i-1][j][1], dp[i-1][j][2]) + w[i][0];
			dp[i][j][1] = min(dp[i-1][j][0], dp[i-1][j][2]) + w[i][1];
			dp[i][j][2] = min(dp[i-1][j][0], dp[i-1][j][1]) + w[i][2];
		}
	}
	int res[6];
	res[0] = dp[N][0][2] = min(dp[N-1][0][0], dp[N-1][0][1]) + w[N][2];
	res[1] = dp[N][0][1] = min(dp[N-1][0][0], dp[N-1][0][2]) + w[N][1];
	res[2] = dp[N][1][0] = min(dp[N-1][1][1], dp[N-1][1][2]) + w[N][0];
	res[3] = dp[N][1][2] = min(dp[N-1][1][0], dp[N-1][1][1]) + w[N][2];
	res[4] = dp[N][2][0] = min(dp[N-1][2][1], dp[N-1][2][2]) + w[N][0];
	res[5] = dp[N][2][1] = min(dp[N-1][2][0], dp[N-1][2][2]) + w[N][1];

	int mini = INF;
	for(int i = 0; i < 6; i++)
		mini = min(mini, res[i]);
	cout << mini;
}
