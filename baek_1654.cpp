#include <iostream>

using namespace std;

int K, N;
int T[10101];

int f(long long len){
	int sum = 0;
	for(int i = 0; i < K; i++){
		if(T[i] >= len)
			sum += T[i]/len;
	}

	return sum;
}

int main(void){
	cin >> K >> N;
	for(int i = 0; i < K; i++){
		cin >> T[i];
	}

	long long lo = 0, hi = 3e9;

	for(int i = 0; i < 40; i++){
		long long mid = (lo+hi)/2;
		if(f(mid) >= N) lo = mid;
		else hi = mid;
	}

	cout << lo << '\n';
}
