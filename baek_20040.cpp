#include <bits/stdc++.h>

using namespace std;

const int MN = 501010;
const int INF = 1e9;
int N, M, par[MN], rnk[MN];

void init(int n) {
	for(int i = 0; i < n; i++) 
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
	vector<int> res;
	for(int i = 1; i <= M; i++) {
		int a, b;	cin >> a >> b;
		if(find(a) == find(b)) 
			res.push_back(i);
		else 
			unite(a,b);
	}
	if(!res.empty())
		cout << res[0];
	else
		cout << 0;
}
