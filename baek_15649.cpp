#include <bits/stdc++.h>

using namespace std;
const int MN = 10;
const int INF = 1e9;
int N, M;

bool visit[MN];
vector<int> num;
void dfs(int depth) 
{
	if(depth <= 0) {
		for(int a : num)
			cout << a << ' ';
		cout << '\n';
		return;
	}

	for(int i = 1; i <= N; i++) {
		if(!visit[i]) {
			visit[i] = true;
			num.push_back(i);
			dfs(depth-1);
			num.pop_back();
			visit[i] = false;
		}
	}
	
}

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N >> M;
	dfs(M);
}
