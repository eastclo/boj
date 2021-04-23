#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll cal(ll n) {
	ll ret = 0;
	while(n) {
		ret += n%10;	
		n /= 10;
	}
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	while(1) {
		int N;	cin >> N;
		if(!N) return 0;

		ll S = cal(N);
		int p = 11;
		while(1) {
			if(S == cal(N*p)) {
				int q = 11;
				bool chk = true;
				while(q < p) {
					if(S == cal(N*q))
						chk = false;
					q++;
				}
				if(chk) {
					cout << p << '\n';
					break;
				}
			}
			p++;
		}
	}
}
