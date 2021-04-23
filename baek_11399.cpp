#include <bits/stdc++.h>

using namespace std;
const int MN = 1001;
int arr[MN];
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N;	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N);
	int res = arr[0];
	for(int i = 1; i < N; i++) {
		arr[i] += arr[i-1];
		res += arr[i];
	}
	cout << res;
}
