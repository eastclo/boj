#include <bits/stdc++.h>

using namespace std;
const int MN = 65;

int arr[MN][MN];

bool check(int a, int b, int c, int d){
	int num = arr[a][b];
	for(int i = a; i <= c; i++)
		for(int j = b; j <= d; j++)
			if(num != arr[i][j])
				return false;
	return true;
}

void dnc(int a, int b, int c, int d){
	if(check(a, b, c, d))
		cout << arr[a][b];
	else{
		int xmid = (a + c) / 2;
		int ymid = (b + d) / 2;
		cout << '(';
		dnc(a, b, xmid, ymid);
		dnc(a, ymid + 1, xmid, d);
		dnc(xmid + 1, b, c, ymid);
		dnc(xmid + 1, ymid + 1, c, d);
		cout << ')';
	}
}

int main(void){
	int N;  cin >> N;
	for(int i = 1 ; i <= N; i++){
		for(int j = 1; j <= N; j++){
			scanf("%1d", &arr[i][j]);
		}
	}

	dnc(1, 1, N, N);
	cout << '\n';
}
