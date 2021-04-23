#include <bits/stdc++.h>

using namespace std;

const int MN = 26;

string g[MN];
bool visited[MN][MN];
vector<int> res;
int di[4] = {0, 0, 1, -1};
int dj[4] = {1, -1, 0, 0};
int N;

int dfs(int x, int y) {
	visited[x][y] = true;

	int ret = 1;
	for(int d = 0; d < 4; d++) {
		int nx = x + di[d];
		int ny = y + dj[d];
		if(0 <= nx && nx < N && 0 <= ny && ny < N) 
			if(!visited[nx][ny] && g[nx][ny] == '1')
				ret += dfs(nx, ny);
	}
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N;
	for(int i = 0; i < N; i++) 
		cin >> g[i];

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if(!visited[i][j] && g[i][j]=='1') 
				res.push_back(dfs(i, j));
		}
	}

	cout << res.size() << '\n';
	sort(res.begin(), res.end());
	for(int a : res)
		cout << a << '\n';
}
