#include <bits/stdc++.h>

using namespace std;
int N, K;
int f(int n) {
	int ret = 0;
	for(int i = 1; i <= N; i++)
		ret += min(N, n/i);
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N >> K;

	int lo = 0, hi = 1e9+1;
	for(int i = 0; i < 40; i++) {
		int mid = (lo + hi) / 2;
		if(f(mid) < K) 
			lo = mid;
		else
			hi = mid;
	}
	cout << hi;
}
