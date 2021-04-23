#include <bits/stdc++.h>

using namespace std;
const int MN = 10;
const int INF = 1e9;
int N, M;

bool visited[MN];
vector<int> num;
void dfs(int prev, int depth) 
{
	if(depth <= 0) {
		for(int a: num)
			cout << a << ' ';
		cout << '\n';
		return;
	}

	for(int i = prev + 1; i <= N; i++) {
		if(!visited[i]) {
			visited[i] = true;
			num.push_back(i);
			dfs(i, depth-1);
			num.pop_back();
			visited[i] = false;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N >> M;
	dfs(0, M);
}
