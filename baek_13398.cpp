#include <bits/stdc++.h>

using namespace std;

const int MN = 100101;
const int INF = 1e9;

int arr[MN];
int dp[MN][2];
int mindp[MN];
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N;	cin >> N;
	for(int i = 1; i <= N; i++) 
		cin >> arr[i];
	
	int res = -INF;
	for(int i = 1; i <= N; i++) {
		dp[i][0] = max(dp[i-1][0], 0) + arr[i];	
		dp[i][1] = max(dp[i-1][0] - arr[i-1], dp[i-1][1]) + arr[i];

		res = max(res, max(dp[i][0], dp[i][1]));
	}
	cout << res;	
}
