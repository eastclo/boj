#include <bits/stdc++.h>

using namespace std;

const int MN = 31;
const int MW = 40101;

int dp[MN][MW];
int arr[MN], N;
void dfs(int i, int x) {
	if(i > N) return;
	if(dp[i][x]) return;
	dp[i][x] = 1;

	dfs(i+1, x + arr[i]);
	dfs(i+1, x);
	dfs(i+1, abs(x-arr[i]));
}

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N;
	for(int i = 0; i < N; i++) 
		cin >> arr[i];
	dfs(0, 0);	
	int T;	cin >> T;
	while(T--) {
		int a;	cin >> a;
		cout << (dp[N][a] ? "Y " : "N ");
	}
}
