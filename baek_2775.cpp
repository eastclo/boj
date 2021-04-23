#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int T;	cin >> T;

	while(T--) {
		int K, N;	cin >> K >> N;
		int arr[15];
		for(int i = 1; i <= 14; i++)
			arr[i] = i;

		for(int i = 1; i <= K; i++) {
			for(int j = N; j >= 1; j--) {
				int tmp = 0;
				for(int k = 1; k <= j; k++) {
					tmp += arr[k];
				}
				arr[j] = tmp;
			}
		}
		cout << arr[N] << '\n';
	}
}
