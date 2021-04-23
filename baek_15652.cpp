#include <bits/stdc++.h>

using namespace std;
const int MN = 10;
const int INF = 1e9;
int N, M;

vector<int> num;
void dfs(int prev, int depth) 
{
	if(depth <= 0) {
		for(int a: num)
			cout << a << ' ';
		cout << '\n';
		return;
	}

	for(int i = prev; i <= N; i++) {
		num.push_back(i);
		dfs(i, depth-1);
		num.pop_back();
	}
}

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N >> M;
	dfs(1, M);
}
