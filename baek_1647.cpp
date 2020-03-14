#include <iostream>
#include <algorithm>

using namespace std;

const int MN = 1e5;
const int MM = 1e6;

struct edge{
	int u, v;
	int w;
};

edge arr[MM];
int par[MN], rnk[MN];

void init(int N){
	for(int i = 0; i < N; i++){
		par[i] = i, rnk[i] = 1;
	}
}

int find(int x){
	if(par[x] == x)
		return x;
	else
		return par[x] = find(par[x]);
}

void unite(int x, int y){
	x = find(x), y = find(y);
	if( x == y )
		return;
	if( rnk[x] > rnk[y] )
		swap(x, y);
	par[x] = y;
	if( rnk[x] == rnk[y] )
		rnk[y]++;
}

int main(void){
	int N, M;       cin >> N >> M;

	init(N);
	for(int i = 0; i < M; i++){
		cin >> arr[i].u >> arr[i].v >> arr[i].w;
		arr[i].u--, arr[i].v--;
	}

	sort(arr, arr + M, [](const edge& a, const edge& b){
			return a.w < b.w;
			});

	int cnt = 0;
	int res = 0;
	for(int i = 0; i < M; i++){
		int x = arr[i].u;
		int y = arr[i].v;
		if(find(x) != find(y)){
			unite(x, y);
			res += arr[i].w;
			cnt++;
		}
		if(cnt == (N-2))
			break;
	}

	cout << res << '\n';

}
