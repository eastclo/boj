#include <iostream>

using namespace std;

long long dp[91][2];

int main(void) {
	int N;  cin >> N;

	dp[1][0] = 0;
	dp[1][1] = 1;

	for(int n = 2; n <= N; n++){
		dp[n][0] = dp[n-1][0] + dp[n-1][1];
		dp[n][1] = dp[n-1][0];
	}

	cout << dp[N][0] + dp[N][1] << '\n';
}
