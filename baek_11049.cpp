#include <bits/stdc++.h>

using namespace std;
#define P pair<int,int>
#define X first
#define Y second
const int MN = 511;
const int INF = 2e9;

P arr[MN];
int dp[MN][MN];
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N;	cin >> N;
	for(int i = 1; i <= N; i++)
		cin >> arr[i].X >> arr[i].Y;

	for(int n = 2; n <= N; n++) {
		for(int i = 0, j = i + n; j <= N; i++, j++) {
			dp[i][j] = INF;
			for(int k = i+1; k <= j; k++)
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + arr[i+1].X * arr[k].Y * arr[j].Y);
		}
	}
	cout << dp[0][N];
}
