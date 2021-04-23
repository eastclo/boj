#include <bits/stdc++.h>

using namespace std;

const int MN = 501;

int N, M;
int arr[MN][MN];
int dp[MN][MN];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int dfs(int x, int y) {
	if(!x && !y)
		return 1;
	if(dp[x][y] != -1)
		return dp[x][y];

	dp[x][y] = 0;	
	for(int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if(0 <= nx && nx < N && 0 <= ny && ny < M && arr[x][y] < arr[nx][ny])
			dp[x][y] += dfs(nx, ny);
	}

	return dp[x][y];
}

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);

	cin >> N >> M;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			cin >> arr[i][j];
			dp[i][j] = -1;
		}
	}

	cout << dfs(N-1, M-1);
}
