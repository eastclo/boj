#include <bits/stdc++.h>

using namespace std;
const int MN = 501;

int dp[MN][MN];
int main()
{
    ios::sync_with_stdio(false);	cin.tie(NULL);
	int N;	cin >> N;
	for(int i = 0; i < N; i++) 
		for(int j = 0; j <= i; j++) 
			cin >> dp[i][j];

	int res = 0;
	for(int i = 1; i < N; i++) {
		dp[i][0] = dp[i-1][0] + dp[i][0];
		for(int j = 1; j <= i; j++)
			dp[i][j] += max(dp[i-1][j], dp[i-1][j-1]);
	}
	for(int i = 0; i < N; i++) 
		res = max(res, dp[N-1][i]);

	cout << res;
}