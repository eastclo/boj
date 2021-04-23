#include <bits/stdc++.h>

using namespace std;
#define P pair<int,int>
#define X first
#define Y second

const int MN = 2010;
const int INF = 1e9;
int dist[MN];
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int T;	cin >> T;
	while(T--) {
		int N, M, K;
		cin >> N >> M >> K;
		int S, U, V;
		cin >> S >> U >> V;

		vector<int> res;
		vector<P> g[MN];
		vector<int> dest(K,0);
		fill(dist, dist + N + 1, INF);

		for(int i = 0; i < M; i++) {
			int u, v, w;	cin >> u >> v >> w;
			w *= 2;
			if((u == V || u == U) && (v == V || v == U))
				w--;
			g[u].push_back({w, v});
			g[v].push_back({w, u});
		}

		for(int i = 0; i < K; i++) 
			cin >> dest[i];

		priority_queue<P,vector<P>,greater<P>> pq;
		dist[S] = 0;
		pq.push({0, S});
		
		while(!pq.empty()) {
			P cur = pq.top();	pq.pop();
			int w = cur.X;
			int n = cur.Y;

			if(dist[n] < w) continue;

			for(P next : g[n]) {
				if(dist[next.Y] > w + next.X) {
					dist[next.Y] = w + next.X;
					pq.push({dist[next.Y], next.Y});
				}
			}
		}

		for(int n : dest) 
			if(dist[n] % 2)
				res.push_back(n);
		sort(res.begin(), res.end());
		for(int n : res)
			cout << n << ' ';
		cout << '\n';
	}
}
