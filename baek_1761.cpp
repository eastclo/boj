#include <iostream>
#include <vector>
using namespace std;

const int MN = 40001;

vector<pair<int,int>> G[MN];
pair<int,int> dp[20][MN];
int h[MN];

void DFS(int n, int prev){
	for(pair<int,int> node : G[n]){
		int next = node.first;
		if(next == prev) continue;

		dp[0][next] = make_pair(n, node.second);
		h[next] = h[n] + 1;

		DFS(next, n);
	}
}

int LCA(int a, int b){
	int res = 0;
	if(h[a] < h[b]) swap(a, b);
	int gap = h[a] - h[b];
	for(int i = 0; i < 20; i++){
		if(gap & (1<<i)){
			res += dp[i][a].second;
			a = dp[i][a].first;
		}
	}
	if(a == b) return res;

	for(int i = 19; i >= 0; i--){
		if(dp[i][a].first != dp[i][b].first){
			res += dp[i][a].second + dp[i][b].second;
			a = dp[i][a].first, b = dp[i][b].first;
		}
	}
	res += dp[0][a].second + dp[0][b].second;
	return res;
}

int main(void){
	ios::sync_with_stdio(false);    cin.tie(NULL);
	int N;  cin >> N;

	for(int i = 0; i < N -1; i++){
		int u, v, w;    cin >> u >> v >> w;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	DFS(1, 0);

	for(int i = 1; i < 20; i++)
		for(int j = 1; j <= N; j++)
			dp[i][j] = make_pair(dp[i-1][dp[i-1][j].first].first, dp[i-1][dp[i-1][j].first].second + dp[i-1][j].second);  

	int Q;  cin >> Q;
	while(Q--){
		int u, v;       cin >> u >> v;
		cout << LCA(u, v) << '\n';;
	}
}
