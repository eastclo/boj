#include <bits/stdc++.h>

using namespace std;
#define ll long long

const ll MN = 201; 
const ll MOD = 1e9;

ll dp[MN][MN];
ll solve(ll n, ll k) {
	ll &ret = dp[n][k];
	if(k == 1)
		return 1;
	if(ret != -1)
		return ret;

	ret = 0;
	for(ll i = 0; i <= n; i++) 
		ret += solve(i, k-1) % MOD;	

	return ret % MOD;
}

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	ll N, K;	cin >> N >> K;

	memset(dp, -1, sizeof(dp));
	cout << solve(N, K);
}
