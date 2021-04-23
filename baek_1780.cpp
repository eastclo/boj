#include <bits/stdc++.h>

using namespace std;
const int MN = 2200;

int arr[MN][MN];
int N, res[3];

int check(int x, int y, int n) {
	for(int i = x; i < x+n; i++) 
		for(int j = y; j < y+n; j++) 
			if(arr[i][j] != arr[x][y])
				return -2;
	return arr[x][y];
}

void dnc(int x, int y, int n) {
	int ret = check(x, y, n); 

	if(ret == -2) {
		int nextn = n/3;
		dnc(x, y, nextn);
		dnc(x+nextn, y, nextn);
		dnc(x, y+nextn, nextn);
		dnc(x+nextn, y+nextn, nextn);
		dnc(x+nextn*2, y, nextn);
		dnc(x+nextn*2, y+nextn, nextn);
		dnc(x+nextn*2, y+nextn*2, nextn);
		dnc(x, y+nextn*2, nextn);
		dnc(x+nextn, y+nextn*2, nextn);
	}
	else  
		res[ret+1]++;
}

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N;

	for(int i = 0; i < N; i++) 
		for(int j = 0; j < N; j++) 
			cin >> arr[i][j];

	dnc(0,0,N);
	cout << res[0] << '\n' << res[1] << '\n' << res[2];
}
