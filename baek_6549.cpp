#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int MN = 100101;
const int INF = 1e9;

ll arr[MN];
ll dnc(int l, int r) {
	if(l == r)
		return arr[l];

	ll mid = (l+r)/2;
	ll tmp1 = dnc(l, mid);
	ll tmp2 = dnc(mid+1, r);
	ll ret =  max(tmp1, tmp2);

	ll L = mid, R = mid + 1;
	ll h = min(arr[L], arr[R]);
	ret = max(ret, (R - L + 1)*h);
	while(l < L || R < r) {
		if(l == L) h = min(h, arr[++R]);
		else if(r == R) h = min(h, arr[--L]);
		else if(arr[L-1] > arr[R+1]) h = min(h, arr[--L]);
		else h = min(h, arr[++R]);
		ret = max(ret, (R - L + 1)*h);
	}
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	while(1) {
		int N;	cin >> N;

		if(!N) break;

		for(int i = 0; i < N; i++)
			cin >> arr[i];
		
		cout << dnc(0, N-1) << '\n';
	}
}
