#include <bits/stdc++.h>

using namespace std;

const int MN = 101;
const int MM = 10101;
const int INF = 1e9;
struct edge{ 
	int u,v;
	double w;
};
int N, par[MN], rnk[MN];
edge w[MM];
pair<double, double> node[MN];

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

	for(int i = 0; i < N; i++) 
		cin >> node[i].first >> node[i].second;
	int cnt = 0;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if(i==j) continue;
			w[cnt].u = i;
			w[cnt].v = j;
			double a, b, c, d;
			a = node[i].first;
			b = node[i].second;
			c = node[j].first;
			d = node[j].second;
			w[cnt++].w = sqrt((a-c)*(a-c) + (b-d)*(b-d));
		}
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
