#include <bits/stdc++.h>

using namespace std;
#define P pair<int,int>
#define X first
#define Y second

const int MN = 1001;
const int INF = 1e9;

int g[MN][MN];
bool visited[MN][MN];
int di[4] = {0, 0, 1, -1};
int dj[4] = {1, -1, 0, 0};
int res[MN][MN];
int N, M;

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	cin >> M >> N;
	for(int i = 0; i < N; i++) 
		for(int j = 0; j < M; j++) 
			cin >> g[i][j];

	queue<pair<P,int>> q;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			if(g[i][j] == 1) {
				q.push({{i,j},0});
				visited[i][j] = true;
			}
		}
	}

	int res = 0;
	while(!q.empty()) {
		auto top = q.front();	q.pop();
		P n = top.X;
		int x = n.X;
		int y = n.Y;

		res = top.Y;
		for(int d = 0; d < 4; d++) {
			int nx = x + di[d];
			int ny = y + dj[d];
			if(0 <= nx && nx < N && 0 <= ny && ny < M) {
				if(!visited[nx][ny] && g[nx][ny] == 0) {
					g[nx][ny] = 1;
					q.push({{nx, ny}, top.Y+1});
					visited[nx][ny] = true;
				}
			}
		}
	}
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			if(g[i][j] == 0) {
				cout << -1;
				return 0;
			}
		}
	}
	cout << res;
}
