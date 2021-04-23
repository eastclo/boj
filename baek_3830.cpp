#include <bits/stdc++.h>

using namespace std;
#define ll long long

const int MN = 101001;
ll par[MN], w[MN], rnk[MN];
void init(int n) {
	for(int i = 1; i <= n; i++)
		par[i] = i, w[i] = 0;
}

int find(int x) {
	if(par[x] == x)
		return x;
	int tmp = find(par[x]);
	w[x] += w[par[x]];
	par[x] = tmp;
	return par[x];
}

void unite(int x, int y, int c) {
	int i = find(x), j = find(y);
	if(i == j) return;

	w[j] = w[i]+w[x]+c-w[y];
	par[j] = i;
}

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	while(1) {
		int N, M;	cin >> N >> M;
		if(!N && !M) break;
		init(N);
		
		while(M--) {
			char a; cin >> a;
			if(a == '!') {
				int a, b, c;	cin >> a >> b >> c;

				unite(a, b, c);
				find(a), find(b);
			}
			else {
				int a, b;	cin >> a >> b;

				if(find(a) != find(b))
					cout << "UNKNOWN\n";
				else {
					find(a), find(b);
					cout << w[b]-w[a] << '\n';
				}
			}
		}
	}
}
