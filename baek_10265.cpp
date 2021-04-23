#include <bits/stdc++.h>

using namespace std;

const int MN = 1010;

int N, M;
vector<int> g[MN], rg[MN];
bool visit[MN];
vector<int> st;
vector<vector<int> > scc;
vector<pair<int,int> > sack;
int dp[MN];

void dfs1(int n)
{
	visit[n] = true;
	for(int nxt : g[n]) {
		if(!visit[nxt])
			dfs1(nxt);
	}
	st.push_back(n);
}

void dfs2(int n)
{
	visit[n] = true;
	for(int nxt : rg[n]) {
		if(!visit[nxt])
			dfs2(nxt);
	}

	scc.back().push_back(n);
}

int dfs3(int n)
{
	int cnt = 1;
	visit[n] = true;
	for(int nxt : g[n]) {
		if(!visit[nxt]) 
			cnt += dfs3(nxt);
	}
	return cnt;
}

int main(void)
{
	cin >> N >> M;	
	
	for (int i = 1; i <= N; i++) {
		int n;	cin >> n;
		g[n].push_back(i); //n번 째가 가면 i도 갈 수 있다.
		rg[i].push_back(n);
	}

	for(int i = 1; i <= N; i++) {
		if(!visit[i])
			dfs1(i);
	}

	reverse(st.begin(), st.end()); //위상정렬 상태
	memset(visit, false, sizeof(visit));

	for(int n : st) {
		if(!visit[n]) {
			scc.push_back(vector<int>());
			dfs2(n);
		}
	}
	memset(visit, false, sizeof(visit));

	for(int i = 0; i < scc.size(); i++) {
		if(scc[i].size() > 1)
			sack.push_back({scc[i].size(), dfs3(scc[i][0])});	
		else if(rg[scc[i][0]][0] == scc[i][0])
			sack.push_back({1, dfs3(scc[i][0])});
	}

	sort(sack.begin(), sack.end());

	for(int i = 0; i < sack.size(); i++) {
		for(int j = M; j >= 0; j--) {
			for(int w = sack[i].first; w <= sack[i].second; w++) {
				if(j - w >= 0)
					dp[j] = max(dp[j], dp[j-w] + w);
			}
		}
	}

	cout << dp[M] << '\n';
}
