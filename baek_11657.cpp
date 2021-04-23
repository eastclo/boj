#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define PLL pair<ll,ll>
#define X first
#define Y second

const int MN = 501;
const ll INF = 1e18;

vector<PLL> g[MN];
ll dist[MN];
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N, M;	cin >> N >> M;

	for(int i = 0; i < M; i++) {
		int u, v, w;	cin >> u >> v >> w;
		g[u].push_back({w,v});
	}

	fill(dist, dist+N+1, INF);
	dist[1] = 0;

	bool check = false;
	for(int n = 1; n <= N; n++) {
		for(int i = 1; i <= N; i++) {
			if(dist[i] == INF) continue;
			for(PLL next : g[i]) {
				if(dist[next.Y] > dist[i] + next.X) {
					dist[next.Y] = dist[i] + next.X;
					if(n==N) check = true;
				}
			}
		}
	}

	if(check)
		cout << -1;
	else {
		for(int i = 2; i <= N; i++) {
			if(dist[i] != INF)
				cout << dist[i] << '\n';
			else
				cout << -1 << '\n';
		}
	}
}
