#include <bits/stdc++.h>

using namespace std;
#define ll long long

const int MN = 201;
const int INF = 1e9;
int N, M, K;
int dp[MN][MN];
int comb(int n, int k)
{
	int &ret = dp[n][k];
	if(n == k || k == 0) return ret = 1;
	if(ret != -1) return ret;
	ret = 0;
	ll tmp1 = comb(n-1, k);
	ll tmp2 = comb(n-1, k-1);
	if(tmp1 + tmp2 > INF) return ret = INF;
	return ret = tmp1 + tmp2;
}

void solve(int n, int m, ll cnt)
{
	if(n == 0 && m == 0) return;
	if(n == 0) {
		cout << 'z';
		solve(n, m-1, cnt);
		return;
	}
	if(m == 0) {
		cout << 'a';
		solve(n-1, m, cnt);
		return;
	}
	ll front = dp[n+m-1][m];
	ll back = dp[n+m-1][m-1];
	if(cnt + front >= K) {
		cout << 'a';
		solve(n-1, m, cnt);
	}
	else {
		cout << 'z';
		solve(n, m-1, cnt + front);
	}
}

int main(void)
{
	ios::sync_with_stdio(false);    cin.tie(NULL);
	cin >> N >> M >> K;
	memset(dp, -1, sizeof(dp));
	if(comb(N+M, M) < K) {
		cout << -1; return 0;
	}

	solve(N, M, 0);

}
