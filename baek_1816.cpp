#include <bits/stdc++.h>

using namespace std;
const int MN = 1000001;

bool sieve[MN];
vector<int> pn;
int main(void)
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	for(long long p = 2; p * p < MN; p++) {
		if(sieve[p]) continue;
		for(long long i = p * p; i < MN; i += p)
			sieve[i] = true;
	}
	for(int i = 2; i < MN; i++)
		if(!sieve[i]) pn.push_back(i);

	int N;	cin >> N;
	while(N--) {
		long long S;	cin >> S;
		
		bool check = true;
		for(int num : pn) {
			if(S%num == 0) {
				check = false;
				break;
			}
		}
		if(check)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
}
