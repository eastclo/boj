#include <bits/stdc++.h>

using namespace std;

const int MN = 50;

int dp[MN][2];
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N;	cin >> N;
	dp[0][0] = 1;
	for(int i = 1; i <= N; i++) {
		int a = dp[i-1][1];
		int b = dp[i-1][0] + dp[i-1][1];
		dp[i][0] = a;
		dp[i][1] = b;
	}

	cout << dp[N][0] << ' ' << dp[N][1];
}
