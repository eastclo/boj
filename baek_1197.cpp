#include <iostream>
#include <algorithm>

using namespace std;

struct edge{
	int u, v;
	int w;
};

int par[10000];
int rnk[10000];
edge arr[100000];

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
	if(rnk[x] > rnk[y])
		swap(x, y);
	par[x] = y;

	if(rnk[x] == rnk[y])
		rnk[y]++;
}

int main(void){
	int V, E;	cin >> V >> E;

	for(int i = 0; i < E; i++){
		cin >> arr[i].u >> arr[i].v >> arr[i].w;

		arr[i].u--, arr[i].v--;
	}

	init(V);

	sort(arr, arr + E, [](const edge& a, const edge& b){
			return a.w < b.w;
			});
	int res = 0;
	for(int i = 0; i < E; i++){
		if( find(arr[i].v) != find(arr[i].u) ){
			unite(arr[i].v, arr[i].u);
			res += arr[i].w;
		}
	}
	cout << res << '\n';
}
