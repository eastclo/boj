#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
const int MN = 1010;

vector<int> g[MN];
vector<int> st;
int t[MN], fin[MN];
bool visit[MN];
int T, N, K, W;


void DFS(int n){
	visit[n] = true;
	for(int next : g[n]){
		if(visit[next] == false)
			DFS(next);
	}
	st.push_back(n);
}

int main(void){
	ios::sync_with_stdio(false);	cin.tie(NULL);
	cin >> T;
	while(T--){
		cin >> N >> K;
		for(int i = 1; i <= MN; i++)
			g[i].clear();			
		st.clear();
		memset(t, 0, sizeof(t));
		memset(fin, 0, sizeof(fin));
		memset(visit, false, sizeof(visit));

		for(int i = 1; i <= N; i++)
			cin >> t[i];
		for(int i = 1; i <= K; i++){
			int x, y;	cin >> x >> y;
			g[x].push_back(y);			
		}
		cin >> W;

		for(int i = 1; i <= N; i++){
			if(visit[i] == false)
				DFS(i);
		}
		
		reverse(st.begin(), st.end());

		for(int n : st){
			fin[n] += t[n];
			for(int next : g[n]){
				fin[next] = max(fin[next], fin[n]);
			}
		}
		cout << fin[W] << '\n';
	}
}
