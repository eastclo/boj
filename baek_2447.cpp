#include <bits/stdc++.h>

using namespace std;

int N, cnt;
void dnc(int x, int y, int n)
{
	if((x/n) % 3 == 1 && (y/n) % 3 == 1)
		cout << ' ';
	else {
		if(n / 3 == 0)
			cout << '*';
		else
			dnc(x, y, n / 3);
	}
}

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N;

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) 
			dnc(i, j, N);
		cout << '\n';
	}
}
