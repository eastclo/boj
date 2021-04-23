#include <bits/stdc++.h>

using namespace std;

const int MN = 1001;
struct P {int x, y, w;};
string g[MN];
int N, M, K;	
int dist[MN][MN][11];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N >> M >> K;
	for(int i = 0; i < N ; i++)
		cin >> g[i];

	queue<P> q;
	q.push({0,0,0});
	dist[0][0][0] = 1;
	while(!q.empty()) {
		P top = q.front();	q.pop();
		int cx = top.x;
		int cy = top.y;
		int w = top.w;
		if(cx == N-1 && cy == M-1) {
			cout << dist[cx][cy][w];
			return 0;
		}
		
		for(int d = 0; d < 4; d++) {
			int nx = cx + dx[d];
			int ny = cy + dy[d];
			if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if(dist[nx][ny][w]) continue;

			if(g[nx][ny] == '0') {
				q.push({nx, ny, w});
				dist[nx][ny][w] = dist[cx][cy][w] + 1;
			}
			if(g[nx][ny] == '1' && w < K) {
				q.push({nx, ny, w+1});
				dist[nx][ny][w+1] = dist[cx][cy][w] + 1;
			}
		}
	}
	cout << -1;
}
