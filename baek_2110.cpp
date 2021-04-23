#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int MN = 200101;
const int INF = 1e9;
int N, C;
int arr[MN];
ll f(ll len) {
	ll cnt = 1, start = arr[0];
	for (int i = 1; i < N; i++){
		if (arr[i] - start >= len){
			cnt++;
			start = arr[i];
		}
	}
	return cnt;
}

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N >> C;

	for(int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr, arr + N);
	ll lo = 0, hi = 1e9+1;
	for(int i = 0; i < 40; i++) {
		ll mid = (lo + hi) / 2;
		if(C > f(mid))
			hi = mid;
		else
			lo = mid;
	}
	cout << lo;
}
