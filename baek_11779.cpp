#include <bits/stdc++.h>

using namespace std;
#define P pair<int,int>
#define X first
#define Y second

const int MN = 1010;
const int INF = 1e9;

vector<P> g[MN];
vector<int> city;
int dist[MN];
int prv[MN];
void solve(int n) {
	if(!n) return;
	solve(prv[n]);
	city.push_back(n);
}

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N, M;	cin >> N >> M;
	for(int i = 0; i < M; i++) {
		int u, v, w;	cin >> u >> v >> w;
		g[u].push_back({w,v});
	}
	int st, en;	cin >> st >> en;

	fill(dist, dist+N+1, INF);
	priority_queue<P,vector<P>,greater<P>> pq;
	dist[st] = 0;
	pq.push({0, st});

	while(!pq.empty()) {
		P top = pq.top();	pq.pop();
		int w = top.X;
		int n = top.Y;

		if(dist[n] < w) continue;

		for(P edge : g[n]) {
			if(dist[edge.Y] > dist[n] + edge.X) {
				dist[edge.Y] = dist[n] + edge.X;
				prv[edge.Y] = n;
				pq.push({dist[edge.Y], edge.Y});
			}
		}
	}

	cout << dist[en] << '\n';
	solve(en);
	cout << city.size() << '\n';
	for(int a : city)
		cout << a << ' ';
}
