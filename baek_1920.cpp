#include <bits/stdc++.h>

using namespace std;
const int MN = 100101;

int arr[MN];
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N;	cin >> N;
	for(int i = 0; i < N; i++) 
		cin >> arr[i];

	sort(arr, arr + N);
	int M;	cin >> M;
	for(int i = 0; i < M; i++) {
		int a;	cin >> a;
		cout << binary_search(arr, arr + N, a) << '\n';
	}
}
