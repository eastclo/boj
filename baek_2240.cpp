#include <bits/stdc++.h>

using namespace std;

const int MN = 1001;
const int MM = 31;

int T, W;
int arr[MN]; 
int dp[MN][MM][2]; //dp[i][j][k] : i초 j번째 움직임, k나무에 있을 떄
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	cin >> T >> W;
	for(int i = 1; i <= T; i++)
		cin >> arr[i];

	int res = 0;
	for(int i = 1; i <= T; i++) {
		dp[i][0][0] = dp[i-1][0][0];

		if(arr[i] == 1) dp[i][0][0]++;
		for(int j = 1; j <= W; j++) {
			dp[i][j][0] = max(dp[i-1][j-1][1], dp[i-1][j][0]);
			dp[i][j][1] = max(dp[i-1][j-1][0], dp[i-1][j][1]);
			if(arr[i] == 1) dp[i][j][0]++;
			else dp[i][j][1]++;
			res = max(res, max(dp[i][j][0],dp[i][j][1]));
		}
	}
	cout << res;
}
