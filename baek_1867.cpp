#include <iostream>
#include <queue>

using namespace std;
const int MN = 502*2;
const int INF = 2e9;

int c[MN][MN], f[MN][MN];
vector<int> G[MN];

int MaxFlow(int src, int snk){
	int ret = 0;
	while(1){
		queue<int> q;   q.push(src);
		vector<int> p(MN, -1);  p[src] = 0;
		while(!q.empty() && p[snk] == -1){
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
		for(int i = snk; i != src; i = p[i])
			flow = min(flow, c[p[i]][i] - f[p[i]][i]);
		for(int i = snk; i != src; i = p[i]){
			f[p[i]][i] += flow;
			f[i][p[i]] -= flow;
		}
		ret += flow;
	}
	return ret;
}

int main(void){
	int N, M;       cin >> N >> M;
	for(int i = 0; i < M; i++){
		int a, b;       cin >> a >> b;
		b += 500;
		G[a].push_back(b);
		G[b].push_back(a);
		G[0].push_back(a);
		G[a].push_back(0);
		G[1001].push_back(b);
		G[b].push_back(1001);

		c[a][b] = 1;
		c[0][a] = 1;
		c[b][1001] = 1;
	}
	cout << MaxFlow(0, 1001) << '\n';
}
