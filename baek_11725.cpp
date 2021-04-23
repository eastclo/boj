#include <bits/stdc++.h>

using namespace std;

const int MN = 100101;
const int INF = 1e9;

vector<int> g[MN];
int par[MN];

void dfs(int n) {
	for(int next : g[n]) {
		if(par[next] == -1) {
			par[next] = n;
			dfs(next);
		}
	}
}
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N;	cin >> N;
	for(int i = 0; i < N-1; i++) {
		int u, v;	cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	memset(par, -1, sizeof(par));
	par[1] = 0;
	dfs(1);

	for(int i = 2; i <= N; i++)
		cout << par[i] << '\n';
}
