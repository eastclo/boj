#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX_N = 1000;
const int INF = 1e9;

struct edge{
	int v, w;
	edge(int v, int w) : v(v), w(w) {}
};

vector<edge> G[MAX_N];
int res[MAX_N];
int res_X[MAX_N];

int main(void){
	int N, M, X;    cin >> N >> M >> X;
	X--;

	for(int i = 0; i < M; i++){
		int u, v, w;    cin >> u >> v >> w;
		u--, v--;
		G[u].push_back(edge{v, w});
	}

	using P = pair<int,int>;
	priority_queue<P, vector<P>, greater<P>> pq;

	for(int i = 0; i < N; i++){
		int dist[MAX_N];
		for(int i = 0; i < N; i++)

			dist[i] = INF;
		pq.push(make_pair(0, i));
		dist[i] = 0;

		while(!pq.empty()){
			P cur = pq.top();       pq.pop();
			int cur_w = cur.first;
			int cur_v = cur.second;

			if(dist[cur_v] < cur_w)
				continue;

			for(edge nxt_edge : G[cur_v]){
				int nxt = nxt_edge.v;
				if(dist[nxt] > dist[cur_v] + nxt_edge.w){
					dist[nxt] = dist[cur_v] + nxt_edge.w;
					pq.push(make_pair(dist[nxt], nxt));
				}
			}
		}
		if(i == X){
			for(int i = 0; i < N; i++)
				res[i] += dist[i];
		}
		else
			res[i] += dist[X];
	}
	int ans = 0;

	for(int i = 0; i < N; i++)
		ans = max(ans, res[i]);

	cout << ans << '\n';

}
