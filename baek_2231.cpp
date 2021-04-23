#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N;	cin >> N;

	int res = 0;
	for(int i = 1; i <= N; i++) {
		int tmp = i, num = i;
		while(num){
			tmp += num % 10;
			num /= 10;
		}

		if(tmp == N) {
			res = i; 
			break;
		}
	}

	cout << res;
}
