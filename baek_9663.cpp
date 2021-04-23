#include <bits/stdc++.h>

using namespace std;
const int MN = 16;

int res, N;
int arr[MN][MN];

bool check(int x, int y)
{
	for(int i = 0; i < N; i++) {
		if(arr[i][y] == 1)
			return 0;
		if(x >= i && y >= i && arr[x-i][y-i] == 1)
			return 0;
		if(x >= i && y+i < N && arr[x-i][y+i] == 1)
			return 0;
	}
	return 1;
}

void dfs(int n) {
	if(n == N) {
		res++;
		return;
	}

	for(int i = 0; i < N; i++) {
		if(check(n, i)) {
			arr[n][i] = 1;
			dfs(n+1);
			arr[n][i] = 0;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N;
	dfs(0);
	cout << res;
}
