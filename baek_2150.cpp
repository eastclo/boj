#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
const int MN = 10101;

vector<int> g[MN];
vector<int> rg[MN];
vector<int> st;
vector<vector<int>> scc;
bool visited[MN];

void DFS(int n){
	visited[n] = true;
	for(int next : g[n]){
		if(visited[next] == false){
			DFS(next);
		}
	}
	st.push_back(n);
}

void DFS2(int n){
	visited[n] = true;
	for(int next : rg[n]){
		if(visited[next] == false){
			DFS2(next);
		}
	}
	scc.back().push_back(n);
}

int main(void){
	int V, E;       cin >> V >> E;

	for(int i = 1; i <= E; i++){
		int x, y;       cin >> x >> y;
		g[x].push_back(y);
		rg[y].push_back(x);
	}

	for(int i = 1; i <= V; i++){
		if(visited[i] == false)
			DFS(i);
	}
	reverse(st.begin(), st.end());

	memset(visited, false, sizeof(visited));
	for(int n : st){
		if(visited[n] == false){
			scc.push_back(vector<int>());
			DFS2(n);
		}
	}

	for(int i = 0; i < scc.size(); i++)
		sort(scc[i].begin(), scc[i].end());
	sort(scc.begin(), scc.end());

	cout << scc.size() << '\n';

	for(vector<int> i : scc){
		for(int j : i)
			cout << j << ' ';
		cout << -1 << '\n';
	}

	return 0;
}
