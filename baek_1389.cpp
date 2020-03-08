#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> G[101];

int main(void){
	int N, M;       cin >> N >> M;
	for(int i = 0; i < M; i++){
		int u, v;       cin >> u >> v;

		G[u].push_back(v);
		G[v].push_back(u);
	}

	int num = 2e9;
	int res;

	for(int n = 1; n <= N; n++){
		queue<pair<int,int>> q;
		q.push(make_pair(n,0));
		bool visited[101];
		fill(visited, visited + 101, false);
		visited[n] = true;

		int cnt = 0;
		while(!q.empty()){
			pair<int,int> cur = q.front();
			q.pop();

			for(int nxt : G[cur.first]){
				if(!visited[nxt]){
					q.push(make_pair(nxt, cur.second + 1));
					visited[nxt] = true;
					cnt += cur.second + 1;
				}
			}
		}

		if(num > cnt){
			num = cnt;
			res = n;
		}
	}

	cout << res << '\n';
}
