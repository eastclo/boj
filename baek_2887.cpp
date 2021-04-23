#include <bits/stdc++.h>

using namespace std;

const int MN = 101010;
struct edge{ int u,v,w;};
struct point{ int x,y,z,idx;};
int N, M, par[MN], rnk[MN];
vector<edge> w;
point node[MN];

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

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N;
	init(N);

	for(int i = 0; i < N; i++) {
		cin >> node[i].x >> node[i].y >> node[i].z;
		node[i].idx = i;
	}
	sort(node,node+N, [](point a, point b) {
			return a.x < b.x;
			});
	for(int i = 0; i < N-1; i++) 
		w.push_back({node[i].idx,node[i+1].idx,abs(node[i].x-node[i+1].x)});
	
	sort(node,node+N, [](point a, point b) {
			return a.y < b.y;
			});
	for(int i = 0; i < N-1; i++) 
		w.push_back({node[i].idx,node[i+1].idx,abs(node[i].y-node[i+1].y)});
	
	sort(node,node+N, [](point a, point b) {
			return a.z < b.z;
			});
	for(int i = 0; i < N-1; i++) 
		w.push_back({node[i].idx,node[i+1].idx,abs(node[i].z-node[i+1].z)});

	sort(w.begin(), w.end(), [](edge a, edge b){
			return a.w < b.w;
			});
	int res = 0;

	for(int i = 0; i < w.size(); i++) {
		if(find(w[i].u) != find(w[i].v)) {
			unite(w[i].u, w[i].v);
			res += w[i].w;
		}
	}
	cout << fixed << setprecision(2) << res;
}
