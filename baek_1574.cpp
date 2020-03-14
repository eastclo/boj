#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 2e9;
const int MN = 700;

int c[MN][MN], f[MN][MN];
vector<int> g[MN];
bool M[MN][MN];

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
	int R, C, N;    cin >> R >> C >> N;
	for(int i = 0; i < N; i++){
		int a, b;       cin >> a >> b;
		M[a][b+300] = true;
	}

	for(int i = 1; i <= R; i++){
		for(int j = 301; j <= C+300; j++){
			if(M[i][j] == false){
				g[i].push_back(j);
				g[j].push_back(i);

				c[i][j] = 1;
			}
		}
	}

	for(int i = 1; i <= R; i++){
		g[0].push_back(i);
		g[i].push_back(0);
		c[0][i] = 1;
	}
	for(int i = 301; i <= C+300; i++){
		g[i].push_back(601);
		g[601].push_back(i);
		c[i][601] = 1;
	}

	cout << MaxFlow(0, 601) << '\n';
}
