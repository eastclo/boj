#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9+7;

//나눗셈이 포함되면 MOD연산 분할이 안되기 때문에
//페르마 소정리와 곱셈의 역원을 이용하여 나누기를 곱하기로 치환하는 문제
//a = n!
//b = k!(n-k)!
//ab^(-1) % MOD = (ab^(-1)*1) % MOD = (ab^(-1)*b^(MOD-1)) % MOD = ab^(MOD-2) % MOD

ll fac(int n) {
	ll ret = 1;
	while(n)
		ret = ret * n-- % MOD;
	return ret % MOD;
}

ll pow(ll a, ll n) {
	ll ret = 1;
	while(n) {
		if(n & 1)
			ret = ret * a % MOD;
		n = n / 2;
		a = a * a % MOD;
	}
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N, K;	cin >> N >> K;
	cout << fac(N) * pow(fac(K) * fac(N-K) % MOD, (ll)MOD-2) % MOD;
}
