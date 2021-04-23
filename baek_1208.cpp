#include <bits/stdc++.h>

using namespace std;
#define ll long long

const int MN = 41;
const int MM = 4000101;

int N, S;
int arr[MN];
int cnt[MM];
vector<int> a;
ll res;

void dfs2(int n, int sum) {
	if(n == N) {
		if(S-sum > 2000000 || S-sum < -2000000) return;
		res += cnt[S-sum+2000000];
		return;
	}

	dfs2(n+1, sum);
	dfs2(n+1, sum + arr[n]);
}

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N >> S;
	for(int i = 0; i < N; i++)
		cin >> arr[i];

	for(int i = 0; i < (1 << N/2); i++) {
		int sum = 0;
		for(int j = 0; j < N/2; j++) {
			if(i & (1 << j))
				sum += arr[j];
		}
		cnt[sum+2000000]++;
	}

	dfs2(N/2, 0);

	if(S == 0) res--;
	cout << res;
}
