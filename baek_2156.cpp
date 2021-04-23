#include <iostream>
#include <algorithm>

using namespace std;

int dp[10001][3];
int amt[10001];

int main(void) {
	int N;  cin >> N;
	for(int i = 1; i <= N; i++)
		cin >> amt[i];

	dp[1][0] = 0;
	dp[1][1] = amt[1];
	dp[1][2] = 0;

	dp[2][0] = amt[1];
	dp[2][1] = amt[2];
	dp[2][2] = amt[1] + amt[2];

	dp[3][0] = amt[1] + amt[2];
	dp[3][1] = amt[1] + amt[3];
	dp[3][2] = amt[2] + amt[3];

	for(int n = 4; n <= N; n++){
		dp[n][0] = max(max(dp[n-1][0], dp[n-1][1]), dp[n-1][2]);
		dp[n][1] = max(max(dp[n-2][0], dp[n-2][1]), dp[n-2][2]) + amt[n];
		dp[n][2] = dp[n-1][1] + amt[n];
	}

	cout << max(max(dp[N][1], dp[N][2]), dp[N][0]) << '\n';
}
