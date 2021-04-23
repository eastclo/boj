#include <bits/stdc++.h>

using namespace std;

const int MN = 100101;
const int INF = 1e9;

int N, arr[2][MN], dp[3][MN];
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int T;	cin >> T;
	while(T--) {
		cin >> N;
		for(int i = 1; i <= N; i++) 
			cin >> arr[0][i];
		for(int i = 1; i <= N; i++) 
			cin >> arr[1][i];

		for(int i = 1; i <= N; i++) {
			dp[1][i] = dp[0][i-1] + arr[1][i];
			dp[0][i] = dp[1][i-1] + arr[0][i];

			if(i < 2) continue;
			dp[1][i] = max(dp[1][i], max(dp[0][i-2], dp[1][i-2]) + arr[1][i]);
			dp[0][i] = max(dp[0][i], max(dp[0][i-2], dp[1][i-2]) + arr[0][i]);
		}
		cout << max(dp[1][N], dp[0][N]) << '\n';
		memset(arr, 0, sizeof(arr));
		memset(dp, 0, sizeof(dp));
	}
}
