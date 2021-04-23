#include <bits/stdc++.h>

using namespace std;

const int MN = 101;
const int INF = 1e9;

int g[MN][MN][MN];
bool visited[MN][MN][MN];
int dx[6] = {0, 0, 1, -1, 0, 0};
int dy[6] = {1, -1, 0, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
int N, M, H;
struct Q{ int x, y, z, dep; };

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	cin >> M >> N >> H;
	for(int i = 0; i < H; i++) 
		for(int j = 0; j < N; j++) 
			for(int k = 0; k < M; k++) 
				cin >> g[i][j][k];

	queue<Q> q;
	for(int i = 0; i < H; i++) {
		for(int j = 0; j < N; j++) {
			for(int k = 0; k < M; k++) 
				if(g[i][j][k] == 1) {
					q.push({i,j,k,0});
					visited[i][j][k] = true;
				}
		}
	}

	int res = 0;
	while(!q.empty()) {
		auto top = q.front();	q.pop();
		int x = top.x;
		int y = top.y;
		int z = top.z;

		res = top.dep;
		for(int d = 0; d < 6; d++) {
			int nx = x + dx[d];
			int ny = y + dy[d];
			int nz = z + dz[d];
			if(0 <= nx && nx < H && 0 <= ny && ny < N && 0 <= nz && nz < M) {
				if(!visited[nx][ny][nz] && g[nx][ny][nz] == 0) {
					g[nx][ny][nz] = 1;
					q.push({nx, ny, nz, top.dep+1});
					visited[nx][ny][nz] = true;
				}
			}
		}
	}
	for(int i = 0; i < H; i++) {
		for(int j = 0; j < N; j++) {
			for(int k = 0; k < M; k++) 
				if(g[i][j][k] == 0) {
					cout << -1;
					return 0;
				}
		}
	}
	cout << res;
}
