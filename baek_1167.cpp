#include <iostream>
#include <vector>
using namespace std;

const int MN = 100101;
vector<pair<int,int>> G[MN];
int dp[MN];
int res;

void DFS(int n, int prev){
	dp[n] = 0;
	int mx = 0, mx2 = 0;
	
	for(pair<int, int> node : G[n]){
		int next = node.first, cost = node.second;
		if(next == prev) continue;

		DFS(next, n);
		int val = dp[next] + cost;
		dp[n] = max(dp[n], val);

		if(mx < val){
			mx2 = mx;
			mx = val;	
		}
		else if(mx2 < val)
			mx2 = val;
	}

	res = max(res, mx + mx2);
}

int main(void){
	int N;	cin >> N;
	for(int i = 0; i < N; i++){
		int u, v;	cin >> u >> v;
		while(v != -1){
			int w;	cin >> w;
			G[u].push_back({v, w});
			cin >> v;
		}
	}

	DFS(1, 0);
	cout << res << '\n';
}
