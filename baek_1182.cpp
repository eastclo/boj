#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define P pair<int,int>
#define PLL pair<ll,ll>
#define X first
#define Y second

const int MN = 21;
const int INF = 1e9;
int N, S;
int arr[MN];
int res;
void dfs(int n, int sum) {
	if(n == N) {
		if(sum == S)
			res++;
		return;
	}

	dfs(n+1, sum);
	dfs(n+1, sum + arr[n]);
}

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N >> S;
	for(int i = 0; i < N; i++)
		cin >> arr[i];

	dfs(0, 0);
	if(S == 0) res--;
	cout << res;
}
