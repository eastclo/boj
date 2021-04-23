#include <bits/stdc++.h>

using namespace std;
#define ll long long

const int MN = 201;
const int INF = 1e9;

ll arr[MN][MN], dp[MN][MN];
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N;	cin >> N;
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= N; j++)
			cin >> arr[i][j];

	dp[1][1] = 1;
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			if(arr[i][j] == 0) continue;
			int nxt = arr[i][j];	
			dp[i+nxt][j] += dp[i][j];
			dp[i][j+nxt] += dp[i][j];
		}
	}

	cout << dp[N][N];
}
