#include <bits/stdc++.h>

using namespace std;
#define ll long long

const int MN = 81;

ll dp[MN];
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N;	cin >> N;
	dp[1] = 1;
	for(int i = 2; i <= N; i++) 
		dp[i] = dp[i-1] + dp[i-2];

	cout << dp[N]*4 + dp[N-1]*2;
}
