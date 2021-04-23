#include <bits/stdc++.h>

using namespace std;

const int MN = 10101;

bool sieve[MN];
vector<int> prim;

int main(void)
{
	fill(sieve + 2, sieve + MN, true);

	for(int p = 2; p * p < MN; p++) {
		if(!sieve[p]) continue;
		for(int i = p * p; i < MN; i+=p) 
			sieve[i] = false;
	}

	for(int i = 2; i < MN; i++)
		if(sieve[i]) 
			prim.push_back(i);

	int M, N;	cin >> M >> N;
	int res = 0;
	int min = 0;
	for(int i = 0; i < prim.size(); i++)  {
		if(prim[i] >= M && prim[i] <= N) {
			res += prim[i];
			if(min == 0)
				min = prim[i];
		}
	}

	if(res == 0)
		cout  << -1;
	else
		cout << res << '\n' << min;
}
