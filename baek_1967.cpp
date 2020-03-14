#include <iostream>
#include <vector>
using namespace std;

const int MN = 1e4+1;

vector<pair<int,int>> G[MN];
int h[10101];
void DFS(int n, int prev){
	for(pair<int,int> node : G[n]){
		int v = node.first;
		int w = node.second;
		if(v == prev) continue;

		h[v] = h[n] + w;
		DFS(v, n);
	}
}
int main(void){
	int N;  cin >> N;
	for(int i = 0; i < N - 1; i++){
		int u, v, w;    cin >> u >> v >> w;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	DFS(1, 0);
	int mx = 1;
	for(int i = 1; i <= N; i++){
		if(h[mx] < h[i])
			mx = i;
	}
	for(int i = 1; i <= N; i++)
		h[i] = 0;

	DFS(mx, 0);
	mx = 1;
	for(int i = 1; i <= N; i++){
		if(h[mx] < h[i])
			mx = i;
	}
	cout << h[mx] << '\n';
}
