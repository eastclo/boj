#include <bits/stdc++.h>

using namespace std;
const int MN = 21;
const int INF = 1e9;

int N;	
int w[MN][MN];
int dp[MN][1<<MN];
int solve(int n, int curset) {
	int &ret = dp[n][curset];
	if(n > N) return 0;
	if(ret != -1) return ret;
	ret = INF;

	for(int i = 0; i < N; i++) 
		if(!(curset & (1<<i)))
			ret = min(ret, solve(n+1, curset | (1<<i)) + w[n][i+1]);
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N;
	for(int i = 1; i <= N; i++) 
		for(int j = 1; j <= N; j++) 
			cin >> w[i][j];

	memset(dp, -1, sizeof(dp));
	cout << solve(1, 0);
}
