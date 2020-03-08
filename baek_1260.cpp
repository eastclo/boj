#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> G[1001];
bool visited[1001];

void dfs(int cur){
	visited[cur] = true;
	cout << cur << ' ';

	for(int nxt : G[cur]){
		if(!visited[nxt])
			dfs(nxt);
	}
}

int main(void){
	int N, M, V;    cin >> N >> M >> V;

	for(int i = 0; i < M; i++){
		int u, v;       cin >> u >> v;

		G[u].push_back(v);
		G[v].push_back(u);
	}

	for(int i = 1; i <= N; i++){
		sort(G[i].begin(), G[i].end());
	}

	dfs(V);
	cout << '\n';

	fill(visited, visited + 1001, false);

	queue<int> q;
	q.push(V);
	visited[V] = true;

	while(!q.empty()){
		int cur = q.front(); q.pop();
		cout << cur << ' ';

		for(int nxt: G[cur]){
			if(!visited[nxt]){
				q.push(nxt);
				visited[nxt] = true;
			}
		}
	}
}
