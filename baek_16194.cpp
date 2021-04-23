#include <bits/stdc++.h>

using namespace std;

const int MN = 1010;
const int INF = 1e9;

int arr[MN], dp[MN];
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N;	cin >> N;
	for(int i = 1; i <= N; i++)
		cin >> arr[i];

	fill(dp, dp+N+1, INF);
	dp[0] = 0;
		
	for(int i = 1; i <= N; i++) {
		dp[i] = arr[i];
		for(int j = 1; j <= i; j++)	
			dp[i] = min(dp[i], dp[i-j] + dp[j]);
	}

	cout << dp[N];
}
