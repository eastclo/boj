#include <bits/stdc++.h>

using namespace std;
const int MN = 21;
const int INF = 1e9;

int dp[MN];
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	dp[1] = 1;
	int N;	cin >> N;

	for(int i = 2 ; i <= N; i++) 
		dp[i] = dp[i-1] + dp[i-2];

	cout << dp[N];
}
