#include <bits/stdc++.h>

using namespace std;

const int MN = 101;

vector<int> g[MN];
bool visited[MN];
int dfs(int n) {
	visited[n] = true;
	int ret = 1;
	for(int next : g[n]) {
		if(!visited[next])
			ret += dfs(next);
	}
	return ret;
}
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N, M;	cin >> N >> M;
	for(int i = 0; i < M; i++) {
		int a, b;	cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	cout << dfs(1)-1;
}
