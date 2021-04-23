#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int MN = 1010101;
int N, M;
int h[MN];

ll f(int len) {
	ll ret = 0;
	for(int i = 0; i < N; i++)
		if(h[i] > len)
			ret += h[i]-len;
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N >> M;
	for(int i = 0; i < N; i++)
		cin >> h[i];

	ll lo = 0, hi = 1e9+1;
	for(int i = 0; i < 40; i++) {
		ll mid = (lo + hi) / 2;
		if(M > f(mid))
			hi = mid;
		else
			lo = mid;
	}
	cout << lo;
}
