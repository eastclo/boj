#include <bits/stdc++.h>

using namespace std;

const int MN = 4010101;
bool sieve[MN];
vector<int> prim;
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	for(int i = 2; i * i < MN; i++){
		if(sieve[i]) continue;
		for(int p = i*i; p < MN; p += i)
			sieve[p] = true;
	}
	for(int i = 2; i < MN; i++)
		if(!sieve[i])
			prim.push_back(i);

	int N;	cin >> N;
	int st = 0, en = 0, res = 0;
	int sum = prim[0];
	while(prim[en] <= N) {
		if(sum < N) 
			sum += prim[++en];
		else {
			if(sum == N)
				res++;
			sum -= prim[st++];
		}
	}
	
	cout << res;
}
