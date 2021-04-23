#include <bits/stdc++.h>

using namespace std;

const int MN = 1001;
#define X first
#define Y second

struct P {int x, y, depth, wall;};
string g[MN];
int N, M;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
bool visited[MN][MN][2];
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N >> M;
	for(int i = 0; i < N; i++)
		cin >> g[i];

	if(N == 1 && M == 1) {
		cout << 1;
		return 0;
	}

	queue<P> q;
	q.push({0,0,1,0});

	visited[0][0][0] = true;
	vector<int> res;
	while(!q.empty()) {
		P cur = q.front();	q.pop();
		int cx = cur.x;
		int cy = cur.y;
		if(cx == N-1 && cy == M-1) {
			res.push_back(cur.depth);
			continue;
		}

		for(int d = 0; d < 4; d++) {
			int nx = cx + dx[d];
			int ny = cy + dy[d];

			if(0 <= nx && nx < N && 0 <= ny && ny < M) {
				if(!visited[nx][ny][cur.wall]) {
					if(g[nx][ny] == '0') {
						q.push({nx, ny, cur.depth+1, cur.wall});		
						visited[nx][ny][cur.wall] = true;
					}
					if(g[nx][ny] == '1' && !cur.wall) {
						q.push({nx, ny, cur.depth+1, 1});		
						visited[nx][ny][1] = true;
					}
				}
			}
		}
	}
	if(res.size()) {
		sort(res.begin(), res.end());
		cout << res[0];
	}
	else
		cout << -1;
}
