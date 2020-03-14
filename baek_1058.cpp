#include <bits/stdc++.h>

using namespace std;
const int MN = 51;

vector<int> g[MN];
bool visit[MN];

int main(void){
	int N;	cin >> N;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			char a; cin >> a;	
			if(a == 'Y')
				g[i].push_back(j);
		}
	}

	int res = 0;
	for(int i = 1; i <= N; i++){
		fill(visit + 1, visit + N + 1, false);
		queue<int> q;
		visit[i] = true;
		int cnt = 0;
		for(int next : g[i]){
			if(!visit[next]){
				cnt++;
				q.push(next);
				visit[next] = true;
			}
		}

		while(!q.empty()){
			int cur = q.front();	q.pop();
			for(int next : g[cur])
				if(!visit[next]){
					cnt++;
					visit[next] = true;
				}
		}

		res = max(res, cnt);
	}

	cout << res << '\n';
}
