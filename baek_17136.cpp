#include <bits/stdc++.h>

using namespace std;

const int MN = 11;

int dp[MN][MN];
int arr[MN][MN];
int paper[6] = { 0, 5, 5, 5, 5, 5 };
int N = 10;
void cal() {
	memset(dp, 0, sizeof(dp));
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			if(arr[i][j] == 0) continue;
			dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])) + 1;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);    cin.tie(NULL);
	for(int i = 1; i <= N; i++) 
		for(int j = 1; j <= N; j++) 
			cin >> arr[i][j];


	cal();
	/*
	int T = 25;
	while(T--) {
		int mx = 0, si = -1, sj = -1;

		cal();
		for(int i = 10; i > 0; i--) {
			for(int j = 10; j > 0; j--) {
				dp[i][j] = 	
			}
		}


	}
*/
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			cout << dp[i][j] << ' ';
		}
		cout << '\n';
	}
}
