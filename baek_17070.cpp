#include <bits/stdc++.h>

using namespace std;

const int MN = 20;
int arr[MN][MN], dp[MN][MN][3];
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N;	cin >> N;
	for(int i = 1; i <= N; i++) 
		for(int j = 1; j <= N; j++) 
			cin >> arr[i][j];

	dp[1][2][0] = 1;
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			if(arr[i][j]) continue;
			dp[i][j][0] += dp[i][j-1][2] + dp[i][j-1][0];
			dp[i][j][1] += dp[i-1][j][1] + dp[i-1][j][2];
			if(arr[i-1][j] || arr[i][j-1]) continue;
			dp[i][j][2] += dp[i-1][j-1][0] + dp[i-1][j-1][1] + dp[i-1][j-1][2];
		}
	}

	cout << dp[N][N][0] + dp[N][N][1] + dp[N][N][2];
}
