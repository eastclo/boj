#include <bits/stdc++.h>

using namespace std;
#define P pair<int,int>
#define X first
#define Y second

const int MN = 101;
const int INF = 1e9;

int dp[MN][MN];
int path[MN][MN];
vector<int> res;
void find(int i, int j) {
	if(!path[i][j]) 
		return;
	find(i, path[i][j]);
	res.push_back(path[i][j]);
	find(path[i][j], j);
}
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N, M;	cin >> N >> M;
	fill(&dp[0][0], &dp[MN-1][MN], INF);
	for(int i = 0; i < M; i++) {
		int u, v, w;	cin >> u >> v >> w;
		dp[u][v] = min(dp[u][v], w);
	}

	for(int i = 1; i <= N; i++) 
		dp[i][i] = 0;
	
	for(int k = 1; k <= N; k++) {
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= N; j++) {
				int tmp = dp[i][k] + dp[k][j];
				if(dp[i][j] > tmp) {
					dp[i][j] = tmp;
					path[i][j] = k;
				}
			}
		}
	}

	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			if(dp[i][j] == INF)
				cout << 0 << ' ';
			else
				cout << dp[i][j] << ' ';
		}
		cout << '\n';
	}
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			if(i == j)
				cout << 0;
			else if(dp[i][j] == INF)
				cout << 0;
			else {
				if(!path[i][j]) 
					cout << "2 " << i << ' ' << j;
				else {
					res.push_back(i);
					find(i, j);
					res.push_back(j);
					cout << res.size() << ' ';
					for(int a : res)
						cout << a << ' ';
					res.clear();
				}
			}

			cout << '\n';
		}
	}
}
