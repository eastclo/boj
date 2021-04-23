#include <bits/stdc++.h>

using namespace std;
#define ll long long
int A, B, C;
ll mypow(ll a, ll n) {
	if(n == 1)
		return a % C;
	else if(n%2)
		return mypow(a, n-1) * a % C;
	else {
		ll tmp = mypow(a, n/2) % C;
		return tmp * tmp % C;
	}
}

int main(void)
{
	cin >> A >> B >> C;
	cout << mypow(10, 11) % C;
}
