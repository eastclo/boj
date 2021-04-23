#include <bits/stdc++.h>

using namespace std;
const int MN = 31;
const int INF = 1e9;

int dp[MN][MN];
int comb(int n, int k) {
	if(dp[n][k])
		return dp[n][k];
	if(k == 0 || k == n)
		return 1;
	return dp[n][k] = comb(n-1, k-1) + comb(n-1, k);
}

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int T;	cin >> T;
	while(T--) {
		int N, M;	cin >> N >> M;
		cout << comb(M, N) << '\n';
	}
}
