#include <bits/stdc++.h>

using namespace std;

const int MN = 51;

int g[MN][MN];
bool visited[MN][MN];
int di[4] = {0, 0, 1, -1};
int dj[4] = {1, -1, 0, 0};
int N, M, K;

void dfs(int x, int y) {
	visited[x][y] = true;

	for(int d = 0; d < 4; d++) {
		int nx = x + di[d];
		int ny = y + dj[d];
		if(0 <= nx && nx < N && 0 <= ny && ny < M) 
			if(!visited[nx][ny] && g[nx][ny])
				dfs(nx, ny);
	}
}

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int T;	cin >> T;
	while(T--) {
		cin >> M >> N >> K;
		for(int i = 0; i < K; i++) {
			int b, a;	cin >> b >> a;
			g[a][b] = 1;
		}

		int res = 0;
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < M; j++) {
				if(!visited[i][j] && g[i][j]) {
					dfs(i, j);
					res++;
				}
			}
		}
		cout << res << '\n';

		memset(g, 0, sizeof(g));
		memset(visited, 0, sizeof(visited));
	}
}
