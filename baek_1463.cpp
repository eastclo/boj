#include <iostream>
#include <algorithm>

using namespace std;

int dp[1000001];

int solve(int N){
	if(dp[N] != -1)
		return dp[N];
	/*      int min = solve(N-1);

			if(N % 3 == 0 && min > solve(N/3))
			min = solve(N/3);

			if(N % 2 == 0 && min > solve(N/2))
			min = solve(N/2);
	 */

	dp[N] = solve(N-1);

	if(N % 3 == 0)
		dp[N] = min(dp[N], solve(N/3));

	if(N % 2 == 0)
		dp[N] = min(dp[N], solve(N/2));

	dp[N]++;
	return dp[N];
}

int main(void) {
	int N;  cin >> N;
	fill(dp, dp + N + 1, -1);
	dp[0] = 0;
	dp[1] = 0;

	cout << solve(N) << '\n';
}
