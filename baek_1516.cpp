#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int MN = 501;

vector<int> g[MN];
vector<int> st;
int N;
int t[MN], fin[MN];
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
	cin >> N;
	for(int i = 1; i <= N; i++){
		cin >> t[i];
		while(1){
			int x;  cin >> x;
			if(x == -1) break;
			g[x].push_back(i);
		}
	}
	for(int i = 1; i <= N; i++){
		if(visited[i] == false)
			DFS(i);
	}

	reverse(st.begin(), st.end());
	for(int n : st){
		fin[n] += t[n];
		for(int next : g[n])
			fin[next] = max(fin[next], fin[n]);
	}
	for(int i = 1; i <= N; i++){
		cout << fin[i] << '\n';
	}
}
