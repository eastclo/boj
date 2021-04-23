#include <bits/stdc++.h>

using namespace std;

const int MN = 301;
int N, M;
int g[MN][MN], sub[MN][MN];
bool visited[MN][MN];
int dy[4] = {0, 0, -1, 1};
int dx[4] = {1, -1, 0, 0};

int dfs(int x, int y) {
	visited[x][y] = true;
	int ret = 1;
	for(int d = 0; d < 4; d++) {
		int nx = x + dx[d];
		int ny = y + dy[d];

		if(g[nx][ny] <= 0 || visited[nx][ny]) continue;

		ret += dfs(nx, ny);
	}

	return ret;
}

int main(void)
{
	ios::sync_with_stdio(false);    cin.tie(NULL);
	cin >> N >> M;
	int mx = 0, mi = 0 , mj = 0;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			cin >> g[i][j];

	int res = 1;
	while(1) {
		for(int i = 1; i < N-1; i++) {
			for(int j = 1; j < M-1; j++) {
				if(g[i][j] <= 0) continue;
				int cnt = 0;
				for(int d = 0; d < 4; d++) {
					int ni = i + dx[d];
					int nj = j + dy[d];
					if(g[ni][nj] <= 0)
						cnt++;
				}
				sub[i][j] = cnt;
			}
		}
		int ci=0, cj=0, cnt = 0;
		for(int i = 1; i < N-1; i++) {
			for(int j = 1; j < M-1; j++) {
				if(g[i][j] - sub[i][j] > 0)
					ci = i, cj = j, cnt++;
				g[i][j] -= sub[i][j];
			}
		}

		if(!ci && !cj) {
			cout << 0; return 0;
		}

		if(dfs(ci, cj) != cnt) {
			cout << res; return 0;
		}

		res++;
		memset(sub, 0, sizeof(sub));
		memset(visited, 0, sizeof(visited));
	}
}
