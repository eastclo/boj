#include <bits/stdc++.h>

using namespace std;

const int MN = 101;
const int INF = 1e9;
int N, M;
int dist[MN][MN];
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N >> M;
	fill(&dist[0][0], &dist[MN-1][MN], INF);
	for(int i = 1; i <= N; i++) 
		dist[i][i] = 0;

	for(int i = 0; i < M; i++) {
		int u, v, w;	cin >> u >> v >> w;
		dist[u][v] = min(dist[u][v], w);
	}

	for(int k = 1; k <= N; k++) 
		for(int i = 1; i <= N; i++) 
			for(int j = 1; j <= N; j++) 
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			if(dist[i][j] == INF)
				cout << "0 ";
			else
				cout << dist[i][j] << ' ';
		}
		cout << '\n';
	}
}