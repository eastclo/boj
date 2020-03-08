#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> G[50];

int main(void){
	int N;
	char a;
	scanf("%d", &N);
	scanf("%c", &a);
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			char a;
			scanf("%c", &a);
			if(a == 'Y'){
				G[i].push_back(j);
				G[j].push_back(i);
			}
		}
		char a;
		scanf("%c", &a);
	}

	int res = 0;

	queue<int> q;
	for(int n = 0; n < N; n++){
		int cnt = 0;
		bool visited[50];
		fill(visited, visited + 50, false);
		q.push(n);
		visited[n] = true;

		for(int nxt : G[n]){
			if(!visited[nxt]){
				q.push(nxt);
				visited[nxt] = true;
				cnt++;
			}
		}

		while(!q.empty()){
			int cur = q.front();
			q.pop();
				
			for(int nxt : G[cur]){
				if(!visited[nxt]){
					visited[nxt] = true;
					cnt++;
				}
			}
		}

		res = max(res, cnt);
	}

	cout << res << '\n';
}
