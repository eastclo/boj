#include <bits/stdc++.h>

using namespace std;

int main(void){
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int T;	cin >> T;
	while(T--){
		int N;	cin >> N;
		for(int p = 2; p * p <= N; p++){
			if(N % p == 0){
				int cnt = 0;
				while(N % p == 0){
					N /= p;
					cnt++;
				}
				cout << p << ' ' << cnt << '\n';
			}
		}
		if(N != 1)
			cout << N << ' ' << 1 << '\n';
	}
}

