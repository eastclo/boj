#include <bits/stdc++.h>

using namespace std;
#define P pair<int,int>
#define X first
#define Y second

const int MN = 501;
int N, M, T;
bool visited[MN];
vector<int> g[MN];
void dfs(int n, int prv, bool &check) {
	visited[n] = true;
	for(int next : g[n]) {
		if(visited[next] && next != prv) {
			check = false;
			continue;
		}
		if(!visited[next]) 
			dfs(next, n, check);
	}
}

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	while(1) {
		T++;
		cin >> N >> M;
		if(!N && !M) break;
		memset(visited, 0, sizeof(visited));
		for(int i = 0; i < MN; i++)
			g[i].clear();


		for(int i = 0; i < M; i++) {
			int u, v;	cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}

		int res = 0;
		for(int i = 1; i <= N; i++) {
			bool check = true;
			if(!visited[i]) {
				dfs(i, 0, check);	
				if(check)
					res++;
			}
		}
		if(!res)
			cout << "Case " << T << ": No trees.\n"; 
		else if(res==1)
			cout << "Case " << T << ": There is one tree.\n"; 
		else
			cout << "Case " << T << ": A forest of " << res << " trees.\n";
	}
}
