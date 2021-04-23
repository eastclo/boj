#include <bits/stdc++.h>

using namespace std;

const int MN = 10101;
const int MM = 100101;
const int INF = 2e9;

using P = pair<int, int>;
vector<P> g[MN];
int dist[MN];

int main(void){
	int N, M, U, V;
	cin >> N >> M;
	for (int i = 0; i < M; i++){
		int u, v, w;    cin >> u >> v >> w;
		g[u].push_back({w, v});
		g[v].push_back({w, u});
	}
	cin >> U >> V;
	
	priority_queue<P, vector<P>, less<P> > pq;
	pq.push({INF, U});
	dist[U] = INF;

	while (!pq.empty()) {
		P top = pq.top();	pq.pop();
		int cur_w = top.first;
		int cur = top.second;

		if (cur_w < dist[cur]) continue;

		for (P nxt_node : g[cur]) {
			int nxt_w = nxt_node.first;
			int nxt = nxt_node.second;	

			if (dist[nxt] < min(cur_w, nxt_w)) {
				dist[nxt] = min(cur_w, nxt_w);
				pq.push({dist[nxt], nxt});
			}
		}
	}

	cout << dist[V] << '\n';
}
