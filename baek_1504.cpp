#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX_N = 801;
const int INF = 1e8;

struct edge{
	int v, w;
	edge(int v, int w) : v(v), w(w) {}
};

vector<edge> G[MAX_N];
int dist[MAX_N];
int N, E;

void dijkstra(int node){
	using P = pair<int,int>;
	for(int i = 1; i <= N; i++)
		dist[i] = INF;

	priority_queue<P, vector<P>, greater<P>> pq;
	pq.push(make_pair(0, node));
	dist[node] = 0;

	while(!pq.empty()){
		P cur_edge = pq.top();  pq.pop();
		int cur_w = cur_edge.first;
		int cur = cur_edge.second;

		if(dist[cur] < cur_w)
			continue;

		for(edge nxt_edge : G[cur]){
			int nxt = nxt_edge.v;
			if(dist[nxt] > dist[cur] + nxt_edge.w){
				dist[nxt] = dist[cur] + nxt_edge.w;
				pq.push(make_pair(dist[nxt], nxt));
			}
		}
	}
}

int main(void){
	cin >> N >> E;

	for(int i = 0; i < E; i++){
		int u, v, w;    cin >> u >> v >> w;

		G[u].push_back(edge{v, w});
		G[v].push_back(edge{u, w});
	}

	int pt1, pt2;   cin >> pt1 >> pt2;
	int res1 = 0;
	int res2 = 0;

	dijkstra(1);
	res1 += dist[pt1];
	res2 += dist[pt2];
	dijkstra(pt1);
	res1 += dist[pt2];
	res2 += dist[N];
	dijkstra(pt2);
	res1 += dist[N];
	res2 += dist[pt1];

	res1 = min(res1, res2);

	if(res1 > INF)
		cout << -1 << '\n';
	else
		cout << res1 << '\n';
}
