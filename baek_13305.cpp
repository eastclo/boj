#include <bits/stdc++.h>

using namespace std;
const int MN = 100101;
const int INF = 1e9;

int arr[MN];
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N;	cin >> N;
	for(int i = 0; i < N-1; i++)
		cin >> arr[i];

	long long mnum = INF, res = 0;
	for(int i = 0; i < N-1; i++) {
		long long tmp;	cin >> tmp;
		mnum = min(tmp, mnum);
		res += mnum * arr[i];
	}
	cin >> N;
	cout << res;
}
