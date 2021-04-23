#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define P pair<int,int>
#define PLL pair<ll,ll>
#define X first
#define Y second

const int MN = 101;
const ll INF = 1e18;

ll dist[MN];
int arr[MN];
vector<PLL> g[MN];
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N, st, en, M;	cin >> N >> st >> en >> M;
	fill(dist, dist+MN, -INF);

	for(int i = 0; i < M; i++) {
		int u, v, w;	cin >> u >> v >> w;
		g[u].push_back({-w, v});
	}
	for(int i = 0; i < N; i++)
		cin >> arr[i];
	dist[st] = arr[st];

	bool check = false;
	for(int n = 1; n <= N+100; n++) {
		for(int i = 0; i < N; i++) {
			for(PLL edge : g[i]) {
				if(dist[i] == -INF) continue;
				else if(dist[i] == INF) dist[edge.Y] = INF;
				else if(dist[edge.Y] < dist[i] + edge.X + arr[edge.Y]) {
					dist[edge.Y] = dist[i] + edge.X + arr[edge.Y];
					if(n>=N) dist[edge.Y] = INF;
				}
			}
		}
	}
	if(dist[en] == -INF)
		cout << "gg";
	else if(dist[en] == INF)
		cout << "Gee";
	else
		cout << dist[en];
}
