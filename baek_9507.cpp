#include <bits/stdc++.h>

using namespace std;
#define ll long long

const int MN = 70;

ll dp[MN];
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);

	int T;	cin >> T;
	dp[0] = 1; dp[1] = 1; dp[2] = 2; dp[3] = 4;
	for(int i = 4; i < MN; i++)
		dp[i] = dp[i-1] + dp[i-2] + dp[i-3] + dp[i-4];

	while(T--) {
		int N;	cin >> N;
		cout << dp[N] << '\n';
	}
}
