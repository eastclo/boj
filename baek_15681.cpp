#include <bits/stdc++.h>

using namespace std;

const int MN = 100101;

vector<int> g[MN];
int N, R, Q;
int dp[MN];
int dfs(int n, int prv) {
	int &ret = dp[n];
	ret = 1;
	
	for(int nxt : g[n]) {
		if(nxt == prv) continue;
		ret += dfs(nxt, n);
	}
	
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N >> R >> Q;
	for(int i = 0; i < N-1; i++) {
		int u, v;	cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(R, 0);

	for(int i = 0; i < Q; i++) {
		int q;	cin >> q;
		cout << dp[q] << '\n';
	}
}
