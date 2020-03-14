#include <iostream>

using namespace std;

int main(void){
	int N;	cin >> N;
	int result = 0;

	for(int i = 0; i < N; i++){
		int num;	cin >> num;

		int cnt = 0;
		for(int p = 2; p * p <= num; p++){
			if(num % p == 0){
				while(num % p == 0){
					num /= p;
					cnt++;
				}
			}
		}

		if(cnt == 0 && num != 1)
			result++;
	}

	cout << result << '\n';


}

