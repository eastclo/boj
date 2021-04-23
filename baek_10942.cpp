#include <bits/stdc++.h>

using namespace std;

const int MN = 2001;

int dp[MN][MN], arr[MN];
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N;	cin >> N;
	for(int i = 1; i <= N; i++) {
		cin >> arr[i];
		dp[i][i] = 1;
	}
	for(int i = 1; i < N; i++) {
		if(arr[i] == arr[i+1])
			dp[i][i+1] = 1;
		else
			dp[i][i+1] = 0;
	}

	for(int n = 2; n < N; n++) {
		for(int i = 1, j = i + n; j <= N; i++, j++) {
			if(dp[i+1][j-1] && arr[i] == arr[j])
				dp[i][j] = 1;
		}
	}

	int T;	cin >> T;
	while(T--) {
		int a, b;	cin >> a >> b;
		cout << dp[a][b] << '\n';
	}
}
