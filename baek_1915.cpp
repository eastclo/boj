#include <bits/stdc++.h>

using namespace std;

const int MN = 1010;

int dp[MN][MN];
string arr[MN];
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N, M;	cin >> N >> M;
	for(int i = 1; i <= N; i++) {
		cin >> arr[i];
		arr[i] = ' ' + arr[i];
	}

	int res = 0;
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= M; j++) {
			if(arr[i][j] == '0') continue;
			dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])) + 1;
			res = max(res, dp[i][j]);
		}
	}

	cout << res*res;
}
