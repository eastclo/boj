#include <bits/stdc++.h>

using namespace std;

const int MN = 1010;

int arr[MN], dp[MN], N;
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N;
	for(int i = 1; i <= N; i++) 
		cin >> arr[i];

	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			if(i-j < 0) continue;
			dp[i] = max(dp[i], dp[i-j] + arr[j]);
		}
	}

	cout << dp[N];
}
