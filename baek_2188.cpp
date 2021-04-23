#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 2e9;
const int MN = 402;

vector<int> g[MN];
int c[MN][MN], f[MN][MN];

int MaxFlow(int src, int snk){
	int ret = 0;
	while(1){
		queue<int> q;   q.push(src);
		vector<int> p(MN, -1);  p[src] = 0;
		while(!q.empty() && p[snk] == -1){
			int n = q.front();      q.pop();
			for(int next : g[n]){
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
	for(int i = 1; i <= N; i++){
		int S;  cin >> S;
		for(int j = 0; j < S; j++){
			int b;  cin >> b;
			g[i].push_back(b+200);
			g[b+200].push_back(i);
			c[i][b+200] = 1;
		}
	}
	for(int i = 1; i <= N; i++){
		g[0].push_back(i);
		g[i].push_back(0);
		c[0][i] = 1;
	}
	for(int i = 1; i <= M; i++){
		g[i+200].push_back(401);
		g[401].push_back(i+200);
		c[i+200][401] = 1;
	}

	cout << MaxFlow(0, 401) << '\n';
}
