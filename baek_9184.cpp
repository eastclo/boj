#include <bits/stdc++.h>

using namespace std;
const int MN = 22;
const int INF = 1e9;

int dp[MN][MN][MN];
int dfs(int a, int b, int c) {
	if(a <= 0 || b <= 0 || c <= 0)
		return dp[a][b][c] = 1;

	if(dp[a][b][c])
		return dp[a][b][c];
	if(a < b && b < c) 
		return dp[a][b][c] = dfs(a, b, c-1) + dfs(a, b-1, c-1) - dfs(a, b-1, c);
	else 
		return dp[a][b][c] = dfs(a-1, b, c) + dfs(a-1, b-1, c) + dfs(a-1, b, c-1) - dfs(a-1, b-1, c-1);
}
int main()
{
	while(1) {
		int a, b, c, res;
		scanf("%d %d %d", &a, &b, &c);
		if(a == -1 && b == -1 && c == -1)
			break;

		printf("w(%d, %d, %d) = ", a, b, c);
		if(a <= 0 || b <= 0 || c <= 0) 
			res = 1;
		else {
			if(a > 20 || b > 20 || c > 20)
				a = 20, b = 20, c = 20;
			dfs(a, b, c);
			res = dp[a][b][c];
		}
		
		printf("%d\n", res);
	}
}
