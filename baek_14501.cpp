#include <bits/stdc++.h>

using namespace std;

const int MN = 20;

int dp[MN];

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N;	cin >> N;

	for(int i = 1; i <= N; i++) {
		int a, b;	cin >> a >> b;
		dp[i+1] = max(dp[i+1], dp[i]);
		dp[i+a] = max(dp[i+a], dp[i] + b);
	}
		
	cout << dp[N+1];
}
