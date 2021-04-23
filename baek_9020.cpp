#include <bits/stdc++.h>

using namespace std;

const int MN = 10101;
const int INF = 1e9;

bool sieve[MN];
vector<int> prim;
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);

	sieve[0] = true, sieve[1] = true;
	for(int p = 2; p * p < MN; p++) {
		if(sieve[p]) continue;
		for(int i = p * p; i < MN; i += p)
			sieve[i] = true;
	}

	for(int i = 2; i < MN; i++) 
		if(!sieve[i])
			prim.push_back(i);

	int T;	cin >> T;

	while(T--) {
		int N;	cin >> N;

		int res = 0;
		int min = INF;

		for(int num : prim) {
			if(num > N/2) break;
			
			if(!sieve[N-num]) {
				if(min > N - num) {
					min = N - num;
					res = num;
				}
			}
		}

		cout << res << ' ' << N - res << '\n';
	}
}
