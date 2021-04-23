#include <bits/stdc++.h>

using namespace std;

const int MN = 1010;

int arr[MN][MN];
int dp[MN][MN];
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N, M;	cin >> N >> M;
	for(int i = 1; i <= N; i++) 
		for(int j = 1; j <= M; j++)
			cin >> arr[i][j];

	for(int i = 1; i <= N; i++) 
		for(int j = 1; j <= M; j++)
			dp[i][j] = max(dp[i-1][j], max(dp[i][j-1], dp[i-1][j-1])) + arr[i][j];
	
	cout << dp[N][M];
}
