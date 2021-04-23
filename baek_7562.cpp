#include <bits/stdc++.h>

using namespace std;

const int MN = 301;
struct P{int x,y,depth;};

int g[MN][MN];
bool visited[MN][MN];
int dx[8] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int dy[8] = { 1, -1, 2, -2, 2, -2, 1, -1};
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int T;	cin >> T;
	while(T--) {
		int N;	cin >> N;
		int u, v;	cin >> u >> v;
		int destu, destv;	cin >> destu >> destv;

		queue<P> q;
		q.push({u,v,0});
		visited[u][v] = true;
		while(!q.empty()) {
			P top = q.front();	q.pop();
			int cx = top.x;
			int cy = top.y;

			if(cx == destu && cy == destv) {
				cout << top.depth << '\n';
				break;
			}

			for(int d = 0; d < 8; d++) {
				int nx = cx + dx[d];
				int ny = cy + dy[d];
				if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
				if(!visited[nx][ny]) {
					q.push({nx, ny, top.depth+1});
					visited[nx][ny] = true;
				}
			}
		}


		memset(g, 0, sizeof(g));
		memset(visited, 0, sizeof(visited));
	}
}
