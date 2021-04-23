#include <bits/stdc++.h>

using namespace std;
const int MN = 129;

int arr[MN][MN];
int N, blu, whi;

bool check(int x, int y, int n) {
	for(int i = x; i < x+n; i++) 
		for(int j = y; j < y+n; j++) 
			if(arr[i][j] != arr[x][y])
				return false;
	return true;
}

void dnc(int x, int y, int n) {
	int ret = check(x, y, n); 

	if(ret)
		cout << arr[x][y];
	else {
		cout << '(';
		dnc(x, y, n/2);
		dnc(x, y+n/2, n/2);
		dnc(x+n/2, y, n/2);
		dnc(x+n/2, y+n/2, n/2);
		cout << ')';
	}
}

int main(void)
{
	cin >> N;

	for(int i = 0; i < N; i++) 
		for(int j = 0; j < N; j++) 
			scanf("%1d", &arr[i][j]);

	dnc(0,0,N);
}
