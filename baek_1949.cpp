#include <bits/stdc++.h>

using namespace std;

const int MN = 10101;

int N, arr[MN], dp[MN][2];
vector<int> g[MN];
int dfs(int n, int prv, bool chk) {
	int &ret = dp[n][chk];
	if(ret != -1) return ret;
	if(chk) ret = arr[n];
	else ret = 0;

	for(int nxt : g[n]) {
		if(nxt == prv) continue;

		if(chk) ret += dfs(nxt, n, false);
		else ret += max(dfs(nxt, n, false), dfs(nxt, n, true));
	}
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N;
	for(int i = 1; i <= N; i++) 
		cin >> arr[i];
	for(int i = 0; i < N-1; i++) {
		int u, v;	cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	memset(dp, -1, sizeof(dp));

	cout << max(dfs(1, 0, true), dfs(1, 0, false));
}
