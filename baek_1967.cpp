#include <bits/stdc++.h>

using namespace std;
#define P pair<int,int>
#define X first
#define Y second

const int MN = 10101;

int h[MN];
vector<P> g[MN];
void dfs(int n, int prv) {
	for(P next : g[n]) {
		if(next.Y == prv) continue;
		h[next.Y] = h[n] + next.X;
		dfs(next.Y, n);
	}
}

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N;	cin >> N;
	for(int i = 0; i < N-1; i++) {
		int u, v, w;	cin >> u >> v >> w;
		g[u].push_back({w,v});
		g[v].push_back({w,u});
	}

	dfs(1, 0);
	int mx = 1;
	for(int i = 1; i <= N; i++)
		if(h[mx] < h[i])
			mx = i;
	memset(h, 0, sizeof(h));
	dfs(mx, 0);
	for(int i = 1; i <= N; i++)
		if(h[mx] < h[i])
			mx = i;
	cout << h[mx];
}
