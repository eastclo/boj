#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int T;	cin >> T;
	while(T--) {
		int H, W, N;	cin >> H >> W >> N;

		int len = (N % H) ? N / H + 1 : N / H;
		int fl = (N % H) ? N % H : H; 

		cout << fl;
		if(len < 10)
			cout << 0;
		cout << len << '\n';
	}
}
