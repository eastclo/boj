#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int T;	cin >> T;
	while(T--) {
		int x, y;	cin >> x >> y;
		
		int sub = y - x;
		int cnt = 1;

		long long num = 0;
		int res = 0;

		while(1) {
			res++;
			num += cnt;
			if(num >= sub) {
				cout << res << '\n';
				break;
			}
			
			res++;
			num += cnt;
			if(num >= sub) {
				cout << res << '\n';
				break;
			}

			cnt++;
		}
	}
}
