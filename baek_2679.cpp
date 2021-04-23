#include <bits/stdc++.h>

using namespace std;

const int MN = 1010;
const int INF = 2e9;

vector<int> G[MN];
vector<pair<int,int>> g[MN];
int c[MN][MN], f[MN][MN];       // c[a][b] = a 에서 b로 가는 간선의 용량
int dist[MN];
int MaxFlow(int src, int snk){
	int ret = 0;
	while(1){
		queue<int> q;   q.push(src);
		vector<int> p(MN, -1); p[src] = src;   //최단경로에서 직전에 건너온 경로
		while(!q.empty()){      // 방문하지 않으면 -1
			int n = q.front();      q.pop();
			for(int next : G[n]){
				if(c[n][next] - f[n][next] > 0 && p[next] == -1){
					q.push(next);
					p[next] = n;
				}
			}
		}
		if(p[snk] == -1) break;
		int flow = INF;
		for(int i = snk; i !=src; i=p[i])
			flow = min(flow, c[p[i]][i] - f[p[i]][i]);
		for(int i = snk; i !=src; i=p[i]){
			f[p[i]][i] += flow;
			f[i][p[i]] -= flow;     //유량의 대칭성
		}
		ret += flow;
	}
	return ret;
}

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL);
	int T; cin >> T;
	while(T--) {
		int N, E, A, B;  cin >> N >> E >> A >> B;
		for(int i = 0; i < E; i++){
			int a, b, x;  cin >> a >> b >> x;
			g[a].push_back({b, x});
			G[a].push_back(b);
			G[b].push_back(a);
			c[a][b] += x;
		}

		using P = pair<int,int>;
		priority_queue<P, vector<P>, greater<P>> pq;

		pq.push({INF, A});
		dist[A] = INF;

		while(!pq.empty()){
			P top = pq.top();       pq.pop();
			int cur_w = top.first;
			int cur = top.second;

			if(cur_w < dist[cur])
				continue;

			for(P nxt_edge : g[cur]){
				int nxt = nxt_edge.first;
				int nxt_w = nxt_edge.second;
				if(dist[nxt] < min(cur_w, nxt_w)){
					dist[nxt] = min(cur_w, nxt_w);
					pq.push({dist[nxt], nxt});
				}
			}
		}

		cout<<fixed;
		cout.precision(3);
		cout << (double)MaxFlow(A,B) / dist[B] <<'\n';

		for(int i = 0; i < N; i++) {
			g[i].clear();
			G[i].clear();
		}
		memset(c, 0, sizeof(c));
		memset(f, 0, sizeof(f));
		memset(dist, 0, sizeof(dist));
	}
}
