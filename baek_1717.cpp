#include <bits/stdc++.h>

using namespace std;

const int MN = 1001010;
const int INF = 1e9;
int N, M, par[MN], rnk[MN];

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
	for(int i = 0; i < M; i++) {
		int q, a, b;	cin >> q >> a >> b;
		if(q) {
			if(find(a) == find(b))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
		else 
			unite(a,b);
	}
}
