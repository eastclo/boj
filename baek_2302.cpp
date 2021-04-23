#include <bits/stdc++.h>

using namespace std;

const int MN = 41;

bool vip[MN];
int dp[MN][3];
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N, M;	cin >> N >> M;
	for(int i = 0; i < M; i++) {
		int a;	cin >> a;
		vip[a] = 1;
	}

	dp[1][1] = 1;
	if(!vip[1]) 
		dp[1][2] = 1;

	for(int i = 2; i < N; i++) {
		if(vip[i]) {
			dp[i][1] = dp[i-1][1] + dp[i-1][0];
		}
		else {
			dp[i][0] = dp[i-1][2];
			dp[i][1] = dp[i-1][1] + dp[i-1][0];
			dp[i][2] = dp[i-1][1] + dp[i-1][0];
		}
	}

	dp[N][0] = dp[N-1][2];
	dp[N][1] = dp[N-1][1] + dp[N-1][0];
	if(!vip[N]) 
		cout << dp[N][0] + dp[N][1];
	else
		cout << dp[N][1];
}
