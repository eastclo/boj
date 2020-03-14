#include <iostream>
#include <queue>

using namespace std;

struct Shark{
	int a, b, x;
};

const int INF = 2e9;
const int MN = 102;

vector<int> g[MN];
int c[MN][MN], f[MN][MN];
Shark arr[MN];

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
	int N;  cin >> N;
	for(int i = 1; i <= N; i++){
		cin >> arr[i].a >> arr[i].b >> arr[i].x;
	}

	for(int i = 1; i <= N ; i++){
		for(int j = 1; j <= N; j++){
			if(arr[i].a == arr[j].a && arr[i].b == arr[j].b && arr[i].x == arr[j].x){
				if(i > j){
					g[i].push_back(j+50);
					g[j+50].push_back(i);

					c[i][j+50] = 1;
				}
			}
			else if(arr[i].a >= arr[j].a && arr[i].b >= arr[j].b && arr[i].x >= arr[j].x){
				g[i].push_back(j+50);
				g[j+50].push_back(i);

				c[i][j+50] = 1;
			}
			else continue;

			g[0].push_back(i);
			g[i].push_back(0);
			c[0][i] = 2;

			g[j+50].push_back(101);
			g[101].push_back(j+50);
			c[j+50][101] = 1;
		}
	}

	cout << N - MaxFlow(0, 101) << '\n';
}
