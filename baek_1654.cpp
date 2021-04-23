#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int MN = 10101;
int N, K;
int arr[MN];

ll f(int len) {
	ll cnt = 0;
	for(int i = 0; i < N; i++) 
		cnt += arr[i]/len;
	return cnt;
}

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N >> K;
	for(int i = 0; i < N; i++)
		cin >> arr[i];

	ll lo = 0, hi = 3e9;
	for(int i = 0; i < 40; i++) {
		ll mid = (lo + hi) / 2;
		if(K <= f(mid))
			lo = mid;	
		else
			hi = mid;
	}
	cout << lo;
}
