#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int dp[5001];

int main(void)
{
	int N;	cin >> N;

	fill(dp, dp + 5001, INF);
	dp[3] = 1;
	dp[5] = 1;

	for(int i = 6; i <=N; i++) 
		dp[i] = min(dp[i-3], dp[i-5]) + 1;

	if(dp[N] >= INF)
		cout << -1;
	else
		cout << dp[N];
}
