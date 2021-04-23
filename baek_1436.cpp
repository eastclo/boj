#include <bits/stdc++.h>

using namespace std;
const int MN = 1e7;
const int INF = 1e9;

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N;	cin >> N;
	int res = 0;
	for(int i = 666; i < MN; i++) {
		int num = i;
		int cnt = 0, tmp = 0;
		while(num) {
			if(num % 10 == 6)
				tmp++;
			else {
				cnt = max(cnt, tmp);
				tmp = 0;
			}
			num /= 10;
		}
		cnt = max(cnt, tmp);
		if(cnt >= 3)
			res++;

		if(res == N) {
			cout << i;
			break;
		}
	}
}
