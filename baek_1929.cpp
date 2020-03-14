#include <iostream>

using namespace std;

int main(void){
	int N, M;	cin >> N >> M;

	for(int i = N; i <= M; i++){
		int cnt = 0;
		int num = i;
		for(int p = 2; p * p <= num; p++){
			if(num % p == 0){
				while(num % p == 0){
					num /= p;
					cnt++;
				}
			}
		}

		if(cnt == 0 && num != 1)
			cout << num << '\n';
	}
}

