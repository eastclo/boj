#include <bits/stdc++.h>

using namespace std;

const int MN = 1010;
const int INF = 1e9;

int arr[MN];
int dp[MN];
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N;	cin >> N;
	for(int i = 0; i < N; i++) 
		cin >> arr[i];
	fill(dp, dp + N, INF);
	dp[0] = 0;
	for(int i = 0; i < N; i++) {
		for(int j = i+1; j <= i+arr[i]; j++) 
			dp[j] = min(dp[j], dp[i]+1);
	}
	if(dp[N-1]==INF)
		cout << -1;
	else
		cout << dp[N-1];
}
