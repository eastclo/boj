#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int n; cin >> n;
	if(n-- == 1) {
		cout << 1;
		return 0;
	}

	int num = 6;
	for(int i = 1; ; i++) {
		n = n - num;
		if(n <= 0) {
			cout << i + 1;
			break;
		}
		num += 6;
	}
}
