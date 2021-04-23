#include <bits/stdc++.h>

using namespace std;

const int MN = 1010;

int dp[MN], arr[MN];
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N;	cin >> N;
	for(int i = 1; i <= N; i++)
		cin >> arr[i];

	dp[1] = arr[1];
	for(int i = 2; i <= N; i++) {
		dp[i] = arr[i];
		for(int j = 0; j < i; j++) {
			if(arr[j] < arr[i])
				dp[i] = max(dp[i], dp[j] + arr[i]);
		}
	}

	int res = 0;
	for(int i = 1; i <= N; i++) 
		res = max(res, dp[i]);
	cout << res;
}
