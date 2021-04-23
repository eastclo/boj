#include <bits/stdc++.h>

using namespace std;

const int MN = 10101;
const int MM = 100101;
const int INF = 1e9;
struct edge{ int w,u,v;};
int N, M, par[MN], rnk[MN];
edge w[MM];

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
	cin >> N >> M;
	init(N);
	for(int i = 0; i < M; i++) 
		cin >> w[i].u >> w[i].v >> w[i].w;
	sort(w, w+M, [](edge a, edge b){
			return a.w < b.w;
			});
	int res = 0;
	for(int i = 0; i < M; i++) {
		if(find(w[i].u) != find(w[i].v)) {
			unite(w[i].u, w[i].v);
			res += w[i].w;
		}
	}
	cout << res;
}
