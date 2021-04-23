#include <bits/stdc++.h>

using namespace std;

const int MN = 101;
const int MW = 1010;

int dp[MN][MW];
int arr[MN];
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N, S, M;	cin >> N >> S >> M;
	for(int i = 1; i <= N; i++)
		cin >> arr[i];

	dp[0][S] = 1;
	for(int i = 1; i <= N; i++) {
		for(int j = 0; j <= M; j++) {
			if(dp[i-1][j] == 1) {
				if(j + arr[i] <= M)
					dp[i][j+arr[i]] = 1;
				if(j - arr[i] >= 0)
					dp[i][j-arr[i]] = 1;
			}
		}
	}
	for(int j = M; j >= 0; j--) 
		if(dp[N][j]) {
			cout << j;
			return 0;
		}
	cout << -1;
}
