#include <bits/stdc++.h>

using namespace std;
const int MN = 1010101;
int N;
int arr[MN];
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N;
	int l = 0;
	for(int i = 0; i < N; i++) {
		int a; cin >> a;
		auto it = lower_bound(arr, arr + l, a);
		if(*it==0)
			l++;
		*it = a;
	}

	cout << l;
}
