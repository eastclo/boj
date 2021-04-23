#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define mat vector<vector<ll>>
const ll MOD = 1e9+7;

mat mul(mat a, mat b) {
	mat c(a.size(), vector<ll>(b[0].size(), 0));
	for(int i = 0; i < a.size(); i++) {
		for(int j = 0; j < b.size(); j++) {
			for(int k = 0; k < b[0].size(); k++) {
				c[i][k] += a[i][j] * b[j][k];
				c[i][k] %= MOD;
			}
		}
	}
	return c;
}

mat pow(mat a, ll n) {
	mat ret = a;
	n--;
	while(n) {
		if(n & 1)
			ret = mul(ret, a);
		 n /= 2;
		 a = mul(a, a);
	}
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	ll N;	cin >> N;
	mat a(2, vector<ll>(2, 1));
	a[1][1] = 0;
	mat b(2, vector<ll>(1, 0));
	b[0][0] = 1;

	
	b = mul(pow(a, N), b);
	cout << b[1][0];
}
