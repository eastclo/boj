#include <bits/stdc++.h>

using namespace std;

const int MN = 1010;
const int INF = 1e9;
int N, M;	
int arr[MN][MN];
int dp[MN][MN][3];
bool visited[MN][MN];
int di[3] = {1, 0, 0};
int dj[3] = {0, 1, -1};
int solve(int x, int y, int v) {
	int &ret = dp[x][y][v];	
	if(x == N-1 && y == M-1) return arr[x][y];
	if(ret != -INF) return ret;

	for(int d = 0; d < 3; d++) {
		int ni = x + di[d];
		int nj = y + dj[d];

		if(ni < 0 || ni >= N || nj < 0 || nj >= M) continue;
		if(visited[ni][nj]) continue;
		visited[ni][nj] = true;
		ret = max(ret, solve(ni, nj, d) + arr[x][y]);
		visited[ni][nj] = false;
	}

	return ret;
}
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N >> M;
	for(int i = 0; i < N; i++) 
		for(int j = 0; j < M; j++) 
			cin >> arr[i][j];

	fill(&dp[0][0][0], &dp[MN-1][MN][3], -INF);
	cout << solve(0, 0, 0) << '\n';
}
