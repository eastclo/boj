#include <bits/stdc++.h>

using namespace std;
#define ll long long

const int MN = 31;
const int INF = 1e9;

int N, C;
int arr[MN];
vector<int> a;
ll res;
void dfs(int n, int sum) {
	if(sum > C) return;
	if(n == N) {
		auto hi = upper_bound(a.begin(), a.end(), C-sum);
		res += hi - a.begin();
		return;
	}

	dfs(n+1, sum);
	dfs(n+1, sum + arr[n]);
}

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N >> C;
	for(int i = 0; i < N; i++)
		cin >> arr[i];

	for(int i = 0; i < (1 << N/2); i++) {
		int sum = 0;
		bool check = true;
		for(int j = 0; j < N/2; j++) {
			if(i & (1 << j)) {
				if(sum + arr[j] > C) {
					check = false;
					break;
				}
				sum += arr[j];
			}
		}
		if(check)
			a.push_back(sum);
	}
	sort(a.begin(), a.end());

	dfs(N/2, 0);

	cout << res;
}
