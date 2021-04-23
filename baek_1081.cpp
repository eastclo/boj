#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll sum[10];
ll solve(ll n) {
	ll ret = 0;
	ll digit = 1;
	while(n / digit != 0) {

		ret += sum[9]*digit * (n/(digit*10));
		ll num = (n / digit) - (n / (digit*10))*10;
		ret += sum[num-1]*digit + num*((n%digit)+1);

		digit *= 10;
	}
	return ret;
}
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	ll a, b;	cin >> a >> b;

	for(int i = 1; i < 10; i++)
		sum[i] = sum[i-1] + i;

	ll res = solve(b);
	if(a) res -= solve(a-1);
	
	cout << res;
}
