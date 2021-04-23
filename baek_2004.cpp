#include <iostream>

using namespace std;

int five(int num){
	int cnt = 0;
	for(long long i = 5; num / i >= 1; i *= 5){
		cnt += num / i;
	}
	return cnt;
}
int two(int num){
	int cnt = 0;
	for(long long i = 2; num / i >= 1; i *= 2){
		cnt += num / i;
	}
	return cnt;
}

int main(void){
	int N, M;       cin >> N >> M;

	int cnt_five_N = five(N);
	int cnt_two_N = two(N);

	int cnt_five_M = five(M)+five(N-M);
	int cnt_two_M = two(M)+two(N-M);

	cout << min(cnt_five_N - cnt_five_M, cnt_two_N - cnt_two_M) << '\n';
}
