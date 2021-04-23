#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define mat vector<vector<ll>>

const ll MOD = 1000;

mat mul(mat A, mat B) {
	mat C(A.size(), vector<ll>(B[0].size(), 0));
	for(int i = 0; i < A.size(); i++) {
		for(int j = 0; j < A[0].size(); j++) {
			for(int k = 0; k < B[0].size(); k++) {
				C[i][k] += A[i][j] * B[j][k];
				C[i][k] %= MOD;
			}
		}
	}
	return C;
}
mat pow(mat a, ll n) {
	mat ret = a;
	n--;
	while(n) {
		if(n & 1)
			ret = mul(ret, a);
		n = n / 2;
		a = mul(a, a);
	}

	return ret;
}

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	ll N, B;	cin >> N >> B;
	mat A(N, vector<ll>(N, 0));
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			cin >> A[i][j];
			A[i][j] %= MOD;
		}
	}
		
	A = pow(A, B);

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++)
			cout << A[i][j] << ' ';
		cout << '\n';
	}
}
