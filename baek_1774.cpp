#include <bits/stdc++.h>

using namespace std;

const int MN = 1010;
const int MM = 1010101;
struct edge{ 
	int u,v;
	double w;
};
int N, M, par[MN], rnk[MN];
edge w[MM];
pair<int, int> node[MN];

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

	for(int i = 1; i <= N; i++) 
		cin >> node[i].first >> node[i].second;
	int cnt = 0;
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			if(i==j) continue;
			w[cnt].u = i;
			w[cnt].v = j;
			long long a, b, c, d;
			a = node[i].first;
			b = node[i].second;
			c = node[j].first;
			d = node[j].second;
			w[cnt++].w = sqrt((a-c)*(a-c) + (b-d)*(b-d));
		}
	}
	for(int i = 0; i < M; i++) {
		int a, b;	cin >> a >> b;
		unite(a,b);
	}
	sort(w, w+cnt, [](edge a, edge b){
			return a.w < b.w;
			});
	double res = 0;

	for(int i = 0; i < cnt; i++) {
		if(find(w[i].u) != find(w[i].v)) {
			unite(w[i].u, w[i].v);
			res += w[i].w;
		}
	}
	cout << fixed << setprecision(2) << res;
}
