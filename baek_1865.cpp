#include <bits/stdc++.h>

using namespace std;
#define P pair<int,int>
#define X first
#define Y second

const int MN = 501;
const int INF = 1e9;

int dist[MN];
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int T;	cin >> T;
	while(T--) {
		int N, M, W;	cin >> N >> M >> W;
		vector<P> g[MN];
		fill(dist, dist + MN, INF);
		dist[1] = 0;
		for(int i = 0; i < M; i++) {
			int u, v, w;	cin >> u >> v >> w;
			g[u].push_back({w,v});
			g[v].push_back({w,u});
		}
		for(int i = 0; i < W; i++) {
			int u, v, w;	cin >> u >> v >> w;
			g[u].push_back({-w,v});
		}

		bool check = false;
		for(int n = 1; n <= N; n++) {
			for(int i = 1; i <= N; i++) {
				for(P edge : g[i]) {
					if(dist[edge.Y] > dist[i] + edge.X) {
						dist[edge.Y] = dist[i] + edge.X;
						if(n == N) check = true;
					}
				}
			}
		}

		if(check)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}
