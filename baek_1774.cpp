#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

const int MN = 1000;

struct edge{
	int u, v;
	double w;
	edge(int u, int v, double w) : u(u), v(v), w(w) {}
};

vector<edge> arr;
pair<long long,long long> point[MN+1];
int par[MN+1], rnk[MN+1];

void init(int N){
	for(int i = 1; i <= N; i++){
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

	if(x == y)
		return;

	if(rnk[x] > rnk[y])
		swap(x, y);
	par[x] = y;

	if(rnk[x] == rnk[y])
		rnk[y]++;
}

int main(void){
	int N, M;       cin >> N >> M;
	init(N);

	for(int i = 1; i <= N; i++)
		cin >> point[i].first >> point[i].second;

	for(int i = 1; i < N; i++){
		for(int j = i + 1; j <= N; j++){
			long long a = abs(point[i].first - point[j].first);
			long long b = abs(point[i].second - point[j].second);
			double w = sqrt(a*a + b*b);
			arr.push_back(edge{i,j,w});
		}
	}

	for(int i = 0; i < M; i++){
		int x, y;       cin >> x >> y;
		unite(x, y);
	}

	sort(arr.begin(), arr.end(), [](const edge& a, const edge& b){
			return a.w < b.w;
			});

	double res = 0;
	for(int i = 0; i < arr.size(); i++){
		int x = arr[i].u;
		int y = arr[i].v;
		if(find(x) != find(y)){
			unite(x, y);
			res += arr[i].w;
		}
	}

	printf("%.2lf\n", res);
}
