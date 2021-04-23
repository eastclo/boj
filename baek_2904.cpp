#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

const int MN = 1001010;

queue<pair<int,int>> factor[100];
int tot[MN], arr[100];
vector<int> pn;
bool sieve[MN];

int main(void) {
	int N;  cin >> N;

	for(int i = 0; i < N; i++)
		cin >> arr[i];

	for(int p = 2; p * p < MN; p++){
		if(sieve[p]) continue;
		for(int i = p * p; i < MN; i += p)
			sieve[i] = true;
	}
	for(int i = 2; i < MN; i++)
		if(!sieve[i])
			pn.push_back(i);

	for(int i = 0; i < N; i++){
		int num = arr[i];
		for(int p : pn){
			int cnt = 0;
			if(num % p == 0){
				while(num % p == 0){
					num /= p;
					cnt++;
				}
				factor[i].push({p, cnt});
				tot[p] += cnt;
			}
			if(num == 1) break;
		}
	}

	int res = 1, res2 = 0;
	for(int p : pn){
		int avg = tot[p] / N;

		if(tot[p] >= N)
			res *= pow(p, avg);

		for(int i = 0; i < N; i++){
			int cnt = 0;
			if(!factor[i].empty()){
				pair<int,int> tmp = factor[i].front();
				if(tmp.first == p)
					cnt = tmp.second, factor[i].pop();
			}

			if(cnt < avg)
				res2 += avg - cnt;
		}
	}

	cout << res << ' ' << res2 << '\n';
}
