#include <bits/stdc++.h>

using namespace std;
const int MN = 1000101;
const int MOD = 15746;
int dp[MN];
int main()
{
	int N;	cin >> N;
	dp[1] = 1; dp[2] = 2;
	for(int i = 3; i <= N; i++) 
		dp[i] = (dp[i-1] + dp[i-2]) % MOD;
	cout << dp[N];
}
