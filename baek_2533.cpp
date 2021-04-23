#include <bits/stdc++.h>

using namespace std;

const int MN = 1010101;
const int INF = 1e9;

int dp[MN][2], N;
vector<int> g[MN];
int dfs(int n, int prv, bool chk) {
	int &ret = dp[n][chk];
	if(ret != INF) return ret;
	if(chk) ret = 1;
	else ret = 0;

	for(int nxt : g[n]) {
		if(nxt == prv) continue;

		if(chk) 
			ret += min(dfs(nxt, n, false), dfs(nxt, n, true));
		else
			ret += dfs(nxt, n, true);
	}
	return ret;
}
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	fill(&dp[0][0], &dp[MN-1][2], INF);
	cin >> N;
	for(int i = 0; i < N-1; i++) {
		int u, v;	cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	cout << min(dfs(1, 0, false), dfs(1, 0, true));
}
