#include <bits/stdc++.h>

using namespace std;

const int MN = 100101;
const int INF = 1e9;

int dp[MN];
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N;	cin >> N;
	
	
	fill(dp, dp+N+1, INF);
	dp[0] = 0;
	
	for(int n = 1; n <= N; n++) 
		for(int i = 1; i * i <= n; i++) 
			dp[n] = min(dp[n], dp[n-i*i]+1);
	cout << dp[N];
}
