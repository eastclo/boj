#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 2e9;
const int MN = 1000;

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
		for(int i = snk; i != src; i = p[i]){
			flow = min(flow, c[p[i]][i] - f[p[i]][i]);
		}
		for(int i = snk; i != src; i = p[i]){
			f[p[i]][i] += flow;
			f[i][p[i]] -= flow;
		}
		ret += flow;
	}
	return ret;
}

int main(void){
	int N, P;       cin >> N >> P;
	for(int i = 1; i <= N; i++){
		g[i].push_back(i+400);
		g[i+400].push_back(i);
		c[i][i+400] = 1;
	}
	for(int i = 0; i < P; i++){
		int a, b;       cin >> a >> b;
		g[a+400].push_back(b);
		g[b].push_back(a+400);
		g[a].push_back(b+400);
		g[b+400].push_back(a);

		c[a+400][b] += 1;
		c[b+400][a] += 1;
	}
	cout << MaxFlow(401, 2) << '\n';
}
