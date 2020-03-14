#include <iostream>

using namespace std;

int main(void){
	int N;	cin >> N;

	int cnt = 0;
	for(int i = 1; i <= N; i++){
		if(i % 5 == 0){
			int num = i;
			while(num % 5 == 0){
				num /= 5;
				cnt++;
			}
		}
	}
	cout << cnt << '\n';			
}

