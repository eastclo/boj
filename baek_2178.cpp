#include <bits/stdc++.h>

using namespace std;
#define P pair<int,int>
#define X first
#define Y second

const int MN = 101;
const int INF = 1e9;

string g[MN];
bool visited[MN][MN];
int di[4] = {0, 0, 1, -1};
int dj[4] = {1, -1, 0, 0};
int res[MN][MN];
int N, M;

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N >> M;
	for(int i = 0; i < N; i++) 
		cin >> g[i];

	queue<pair<P,int>> q;
	q.push({{0,0},1});
	visited[0][0] = true;

	while(!q.empty()) {
		auto top = q.front();	q.pop();
		P n = top.X;
		int x = n.X;
		int y = n.Y;

		res[x][y] = top.Y;
		for(int d = 0; d < 4; d++) {
			int nx = x + di[d];
			int ny = y + dj[d];
			if(0 <= nx && nx < N && 0 <= ny && ny < M) {
				if(!visited[nx][ny] && g[nx][ny] == '1') {
					q.push({{nx, ny}, top.Y+1});
					visited[nx][ny] = true;
				}
			}
		}
	}
	cout << res[N-1][M-1];
}
