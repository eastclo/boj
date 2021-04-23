#include <bits/stdc++.h>

using namespace std;
const int MN = 101;
const int INF = 1e9;

int arr[MN];
int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N;	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> arr[i];

	for(int i = 1; i < N; i++) {
		int tmp = gcd(arr[0], arr[i]);
		cout << arr[0] / tmp << '/' << arr[i] /tmp << '\n';
	}
}
