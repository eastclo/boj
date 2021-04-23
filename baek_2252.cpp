#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int MN = 32001;

vector<int> st;
vector<int> g[MN];
bool visited[MN];

void DFS(int n){
	visited[n] = true;
	for(int next : g[n]){
		if(visited[next] == false)
			DFS(next);
	}

	st.push_back(n);
}

int main(void){
	int N, M;       cin >> N >> M;
	for(int i = 0; i < M; i++){
		int x, y;       cin >> x >> y;
		g[x].push_back(y);
	}

	for(int i = 1; i <= N; i++){
		if(visited[i] == false)
			DFS(i);
	}

	reverse(st.begin(), st.end());
	for(int res : st)
		cout << res << ' ';
}
