#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define PLL pair<ll,ll>
#define P pair<int,int>
#define X first
#define Y second

const int MN = 801;
const int INF = 2e9;
int N, M, U, V;
vector<PLL> g[MN];
ll dist[MN];
ll res1, res2;

void dij(int st) {
	fill(dist, dist + 1 + N, INF);
	priority_queue<PLL,vector<PLL>,greater<PLL>> pq;
	pq.push({0, st});
	dist[st] = 0;
	while(!pq.empty()) {
		PLL cur = pq.top();	pq.pop();
		ll n = cur.Y;
		ll w = cur.X;

		if(dist[n] < w) continue;

		for(PLL next : g[n]) {
			if(dist[next.Y] > w + next.X) {
				dist[next.Y] = w + next.X;
				pq.push({dist[next.Y], next.Y});
			}
		}
	}
}
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N >> M;
	for(int i = 0; i < M; i++) {
		int u, v, w;	cin >> u >> v >> w;
		g[u].push_back({w, v});
		g[v].push_back({w, u});
	}
	cin >> U >> V;

	dij(1);
	res1 += dist[U];
	res2 += dist[V];
	dij(U);
	res1 += dist[V];
	res2 += dist[V];
	dij(N);
	res1 += dist[V];
	res2 += dist[U];

	if(res1 >= INF && res2 >= INF)
		cout << -1;
	else
		cout << min(res1, res2);
}
