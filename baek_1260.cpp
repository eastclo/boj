#include <bits/stdc++.h>

using namespace std;

const int MN = 1010;

vector<int> g[MN];
int N, M, V;
bool visited[MN];
void dfs(int n) {
	visited[n] = true;
	cout << n << ' ';
	for(int next : g[n])
		if(!visited[next]) 
			dfs(next);
}
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N >> M >> V;

	for(int i = 0; i < M; i++) {
		int a, b;	cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for(int i = 1; i <= N; i++)
		sort(g[i].begin(), g[i].end());

	dfs(V);
	cout << '\n';
	memset(visited, 0, sizeof(visited));

	queue<int> q;
	q.push(V);
	visited[V] = true;
	while(!q.empty()) {
		int n = q.front();	q.pop();
		cout << n << ' ';
		for(int next : g[n]) {
			if(!visited[next]) {
				q.push(next);
				visited[next] = true;
			}
		}
	}
}
