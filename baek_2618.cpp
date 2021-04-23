#include <bits/stdc++.h>

using namespace std;
#define P pair<int,int>
#define X first
#define Y second

const int MN = 1010;

P arr[MN], a, b;
int dp[MN][MN], tb[MN][MN], N, W, x, y;

int dist(P a, P b) {
	return abs(a.X-b.X) + abs(a.Y-b.Y);
}

int dfs(int x, int y) {
	if(x == W || y == W) return 0;
	int &ret = dp[x][y];
	if(ret != -1) return ret;

	int next = max(x, y) + 1, len1, len2;
	if(!x) len1 = dist(a, arr[next]);
	else len1 = dist(arr[x], arr[next]);
	if(!y) len2 = dist(b, arr[next]);
	else len2 = dist(arr[y], arr[next]);
	
	int i = dfs(next, y) + len1;
	int j = dfs(x, next) + len2;
	if(i <= j) ret = i, tb[x][y] = 1;
	else ret = j, tb[x][y] = 2;
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N >> W;
	for(int i = 1; i <= W; i++) 
		cin >> arr[i].X >> arr[i].Y;
	memset(dp, -1, sizeof(dp));
	a = {1, 1}; b = {N, N};

	cout << dfs(0, 0) << '\n';
	while(W--) {
		int res = tb[x][y], next = max(x,y)+1;
		cout << res << '\n';
		if(res == 1) x = next;
		else y = next;
	}
}
