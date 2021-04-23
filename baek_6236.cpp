#include <iostream>

using namespace std;
int N, M;
int T[101010];

long long f(long long k){
	long long sum = 0, cnt = 1;
	for(int i = 0; i < N; i++){
		if(T[i] > k)
			return M + 1;
		if(sum + T[i] <= k)
			sum += T[i];
		else{
			sum = T[i];
			cnt++;
		}
	}

	return cnt;
}

int main(void){
	cin >> N >> M;
	for(int i = 0; i < N; i++)
		cin >> T[i];

	long long lo = 0, hi = 1e10;
	for(int i = 0; i < 50; i++){
		long long mid = (lo + hi)/2;
		if(f(mid) <= M){
			hi = mid;
		}
		else
			lo = mid;
	}

	cout << hi << '\n';
}
