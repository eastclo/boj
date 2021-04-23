#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define P pair<int,int>
#define PLL pair<ll,ll>
#define X first
#define Y second

const int MN = 1010;
const int MM = 100101;
const int MQ = 200101;
const int INF = 1e9;

struct edge {int u, v;};
struct Query {char q; int n;};
bool added[MM];
edge edges[MM];
Query querys[MQ];
vector<int> g[MN];
int dist[MN];

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N, M, Q;	cin >> N >> M >> Q;
	for(int i = 1; i <= M; i++) 
		cin >> edges[i].u >> edges[i].v;

	fill(added, added+M+1, true);
	for(int i = 0; i < Q; i++) {
		cin >> querys[i].q >> querys[i].n;
		if(querys[i].q == 'U')
			added[querys[i].n] = false;
	}

	for(int i = 1; i <= M; i++) 
		if(added[i]) 
			g[edges[i].u].push_back(edges[i].v);
	
	fill(dist, dist+N+1, INF);
	priority_queue<P, vector<P>, greater<P>> pq;
	pq.push({0, 1});
	dist[1] = 0;

	while(!pq.empty()) {
		P top = pq.top();	pq.pop();
		int w = top.X;
		int n = top.Y;

		if(dist[n] < w) continue;

		for(int next : g[n]) {
			if(dist[next] > dist[n] + 1) {
				dist[next] = dist[n] + 1;
				pq.push({dist[next], next});
			}
		}
	}
	reverse(querys, querys + Q);
	vector<int> res;
	for(int i = 0; i < Q; i++) {
		if(querys[i].q == 'U') {
			edge tmp = edges[querys[i].n];
			g[tmp.u].push_back(tmp.v);
			pq.push({dist[tmp.u], tmp.u});
			
			while(!pq.empty()) {
				P top = pq.top();	pq.pop();
				int w = top.X;
				int n = top.Y;
				if(dist[n] < w) continue;

				for(int next : g[n]) {
					if(dist[next] > dist[n] + 1) {
						dist[next] = dist[n] + 1;
						pq.push({dist[next], next});
					}
				}
			}
		}
		else {
			if(dist[querys[i].n] == INF)
				res.push_back(-1);
			else
				res.push_back(dist[querys[i].n]);
		}
	}
	reverse(res.begin(), res.end());
	for(int a : res)
		cout << a << '\n';
}
