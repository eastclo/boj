#include <bits/stdc++.h>

using namespace std;

const int MN = 1001;
struct P {int x, y;};
string g[MN];
int N, M, num;	
int visited[MN][MN];
int dist[MN][MN];
int group[MN][MN];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int dfs(int x, int y) {
	visited[x][y] = 1;	

	int ret = 1;
	for(int d = 0; d < 4; d++) {
		int nx = x + dx[d];
		int ny = y + dy[d];
		if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
		if(!visited[nx][ny] && g[nx][ny] == '0')
			ret += dfs(nx, ny);
	}
	return ret;
}
void dfs2(int x, int y, int cnt) {
	visited[x][y] = 2;	
	dist[x][y] = cnt;
	group[x][y] = num;

	for(int d = 0; d < 4; d++) {
		int nx = x + dx[d];
		int ny = y + dy[d];
		if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
		if(visited[nx][ny] == 1 && g[nx][ny] == '0') {
			dfs2(nx, ny, cnt);
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N >> M;
	for(int i = 0; i < N ; i++)
		cin >> g[i];
	
	for(int i = 0; i < N ; i++){
		for(int j = 0; j < M; j++){
			if(!visited[i][j] && g[i][j] == '0') {
				++num;
				int tmp = dfs(i, j);
				dfs2(i, j, tmp);
			}
		}
	}

	for(int i = 0; i < N ; i++){
		for(int j = 0; j < M; j++) {
			if(g[i][j] == '0') 
				cout << 0;
			else {
				map<int,int> check;
				int res = 1;
				for(int d = 0; d < 4; d++) {
					int nx = i + dx[d];
					int ny = j + dy[d];
					if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
					if(g[nx][ny] == '0') {
						if(!check[group[nx][ny]]) {
							res += dist[nx][ny];
							check[group[nx][ny]] = 1;
						}
					}
				}
				cout << res % 10;
			}
		}
		cout << '\n';
	}
}
