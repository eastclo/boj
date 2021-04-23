#include <bits/stdc++.h>

using namespace std;

const int MN = 51;

int dp[MN];
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N;	cin >> N;

	dp[0] = 1;

	for(int i = 2; i <= N; i++) {
		dp[i] = dp[i-2]*3;
		for(int j = 0; 2*j <= i-4; j++)
			dp[i] += dp[i-4-j*2]*2;
	}
	cout << dp[N];
}
