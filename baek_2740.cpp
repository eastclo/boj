#include <bits/stdc++.h>

using namespace std;
const int MN = 101;
#define ll long long
#define mat vector<vector<ll>>

mat mul(mat A, mat B) {
	mat C(A.size(), vector<ll>(B[0].size(), 0));
	for(int i = 0; i < A.size(); i++) {
		for(int j = 0; j < A[0].size(); j++) {
			for(int k = 0; k < B[0].size(); k++) {
				C[i][k] += A[i][j] * B[j][k];
			}
		}
	}
	return C;
}

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N, M, K;	cin >> N >> M;
	mat A(N, vector<ll>(M, 0));
	for(int i = 0; i < N; i++)  
		for(int j = 0; j < M; j++)  
			cin >> A[i][j];
	cin >> M >> K;

	mat B(M, vector<ll>(K, 0));
	for(int i = 0; i < M; i++) 
		for(int j = 0; j < K; j++) 
			cin >> B[i][j];
		
	mat C = mul(A, B);

	for(int i = 0; i < C.size(); i++) {
		for(int j = 0; j < C[0].size(); j++)
			cout << C[i][j] << ' ';
		cout << '\n';
	}
}
