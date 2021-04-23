#include <bits/stdc++.h>

using namespace std;
#define ll long long

const int MN = 101;
const int MW = 201;
const int MINUS = 100;

ll arr[MN], dp[MN][MW], N;
ll solve(int i, int sum, int tmp) {
	ll &ret = dp[i][sum+MINUS];
	if(tmp < 0 || tmp > 20)
		return ret = 0;
	if(i == N-1) {
		if(sum == 0)
			return 1;
		else
			return 0;
	}
	if(ret != -1)
		return ret;
	ret = 0;
	ret = solve(i+1, sum-arr[i], tmp+arr[i]) + solve(i+1, sum+arr[i], tmp-arr[i]);
	return ret;
}
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N;
	for(int i = 0; i < N; i++) 
		cin >> arr[i];

	memset(dp, -1, sizeof(dp));
	cout << solve(1, arr[N-1]-arr[0], arr[0]);
}
