#include <bits/stdc++.h>

using namespace std;

const int MN = 101;
const int MK = 10101;

int dp[MK];
int arr[MN];
int N, K;
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N >> K;
	for(int i = 1; i <= N; i++)
		cin >> arr[i];

	dp[0] = 1;
	for(int i = 1; i <= N; i++) {
		for(int j = arr[i]; j <= K; j++) 
			dp[j] += dp[j-arr[i]];
	}

	cout << dp[K];
}
