#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll a, b;
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	cin >> a >> b;

	ll num = 1;

	ll y = 6;
	ll i = 0;
	for(i = 0; i < b; i++) 
		num += y*i + 1;
	for(ll j = 0; j < a; j++, i++)
		num += y*i;

	cout << num;
}
