#include <bits/stdc++.h>

using namespace std;

const int MN = 10101;
int N;
vector<int> g[MN];
vector<int> st;
int w[MN], dp[MN];
bool visited[MN];

void dfs(int n) {
	visited[n] = true;

	for(int nxt : g[n])
		if(!visited[nxt])
			dfs(nxt);

	st.push_back(n);
}

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N;
	for(int i = 1; i <= N; i++) {
		cin >> w[i];
		int cnt;	cin >> cnt;
		while(cnt--) {
			int u;	cin >> u;
			g[u].push_back(i);
		}
	}

	for(int i = 1; i <= N; i++) 
		if(!visited[i])
			dfs(i);
	reverse(st.begin(), st.end());

	int res = 0;
	for(int n : st) {
		dp[n] += w[n]; 
		for(int nxt : g[n])
			dp[nxt] = max(dp[nxt], dp[n]);
		res = max(res, dp[n]);
	}

	cout << res;
}
