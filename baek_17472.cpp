#include <bits/stdc++.h>

using namespace std;

const int MN = 11;
const int INF = 1e9;
int N, M, par[MN], rnk[MN];
int di[4] = {0, 0, 1, -1};
int dj[4] = {1, -1, 0, 0};
int g[MN][MN];
int w[MN][MN];
bool visited[MN][MN];
struct edge{int u,v,w;};
vector<edge> edges;
void init(int n) {
	for(int i = 1; i <= n; i++) 
		par[i] = i, rnk[i] = 1;
}
int find(int x) {
	if(par[x] == x) return x;
	return par[x] = find(par[x]);
}
void unite(int x, int y) {
	x = find(x), y = find(y);
	if(x == y) return;

	if(rnk[x] < rnk[y]) swap(x, y);

	par[y] = x;
	if(rnk[x] == rnk[y])
		rnk[x]++;
}

void dfs(int i, int j, int idx) {
	visited[i][j] = true;
	g[i][j] = idx;

	for(int d = 0; d < 4; d++) {
		int ni = i + di[d];
		int nj = j + dj[d];
		if(ni < 0 || ni >= N || nj < 0 || nj >= M) continue;
		if(visited[ni][nj] || !g[ni][nj]) continue;
		dfs(ni, nj, idx);
	}
}

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N >> M;
	init(N);
	for(int i = 0; i < N; i++) 
		for(int j = 0; j < M; j++) 
			cin >> g[i][j];

	int idx = 1;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			if(!visited[i][j] && g[i][j]) {
				dfs(i,j,idx);
				idx++;
			}
		}
	}

	fill(&w[0][0], &w[MN-1][MN], INF);
	for(int k = 0; k < M; k++) {
		for(int i = 0; i < N; i++) {
			for(int j = i+3; j < N; j++) {
				bool check = true;
				for(int x = i+1; x < j; x++) 
					if(g[x][k]) check = false;
				int a = g[i][k];
				int b = g[j][k];
				if(a && b && a != b && check) {
					w[a][b] = min(w[a][b], j-i-1);
					w[b][a] = min(w[b][a], j-i-1);
				}
			}
		}
	}
	for(int k = 0; k < N; k++) {
		for(int i = 0; i < M; i++) {
			for(int j = i+3; j < M; j++) {
				bool check = true;
				for(int x = i+1; x < j; x++) 
					if(g[k][x]) check = false;
				int a = g[k][i];
				int b = g[k][j];
				if(a && b && a != b && check){
					w[a][b] = min(w[a][b], j-i-1);
					w[b][a] = min(w[b][a], j-i-1);
				}
			}
		}
	}

	for(int i = 1; i < idx; i++) 
		for(int j = 1; j < idx; j++) 
			if(w[i][j] != INF)
				edges.push_back({i,j,w[i][j]});
	sort(edges.begin(), edges.end(), [](edge a, edge b) {
			return a.w < b.w;
			});
	int res = 0;
	int check = 0;
	for(edge a : edges) {
		if(find(a.u) != find(a.v)) {
			unite(a.u, a.v);
			res += a.w;
			check++;
		}
	}
	if(check == idx-2)
		cout << res;
	else
		cout << -1;
}
