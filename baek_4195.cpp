#include <bits/stdc++.h>

using namespace std;

const int MN = 200101;
const int INF = 1e9;
int N, M, par[MN], rnk[MN], cnt[MN];

void init(int n) {
	for(int i = 1; i <= n; i++) 
		par[i] = i, rnk[i] = 1, cnt[i] = 1;
}
int find(int x) {
	if(par[x] == x) return x;
	return par[x] = find(par[x]);
}
void unite(int x, int y) {
	x = find(x), y = find(y);
	if(x == y) return;

	if(rnk[y] > rnk[x]) swap(x, y);

	par[y] = x;
	cnt[x] += cnt[y];
	if(rnk[x] == rnk[y])
		rnk[x]++;
}

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int T; cin >> T;
	while(T--) {
		cin >> N;
		init(MN-1);
		map<string, int> m;
		int idx = 1;
		for(int i = 0; i < N; i++) {
			string a, b;	cin >> a >> b;

			int x, y;
			if(!m[a]) m[a] = idx++;
			if(!m[b]) m[b] = idx++;
			x = m[a];
			y = m[b];
			unite(x, y);
			cout << cnt[find(x)] << '\n';
		}
	}
}
