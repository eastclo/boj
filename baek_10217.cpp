#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define P pair<int,int>
#define PLL pair<ll,ll>
#define X first
#define Y second

const int MN = 101;
const int MM = 10101;
const int INF = 1e9;
struct edge{ int v, c, d; };
struct cmp{
	bool operator()(edge a, edge b){
		return a.d > b.d;
	}
};

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int T;	cin >> T;
	while(T--) {
		int N, M, K;	cin >> N >> M >> K;
		vector<edge> g[MN];
		for(int i = 0; i < K; i++) {
			int u, v, c, d;	cin >> u >> v >> c >> d;
			g[u].push_back({v,c,d});	
		}

		int dist[MN][MM];
		for(int i = 0; i <= N; i++)
			fill(dist[i], dist[i]+M+1, INF);
		priority_queue<edge, vector<edge>, cmp> pq;
		pq.push({1,0,0});
		dist[0][1] = 0;
        bool check = true;
		while(!pq.empty()) {
			edge top = pq.top();	pq.pop();
			int n = top.v;
			int c = top.c;
			int d = top.d;
			if(n == N) {
				check = false;
				cout << dist[n][c] << '\n';
				break;
			}
			if(dist[n][c] < d) continue;
		
			for(edge next_info : g[n]) {
				int next = next_info.v;
				int next_c = c+next_info.c;
				int next_d = d+next_info.d;
				if(next_c <= M) {
					if(next_d < dist[next][next_c]) {
						dist[next][next_c] = next_d;
						pq.push({next, next_c, next_d});
					}
				}
			}
		}

		if(check)
			cout << "Poor KCM\n";
	}
}