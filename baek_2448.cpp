#include <bits/stdc++.h>

using namespace std;

int N, k;
char arr[4000][8000];

void star(int l, int r, int top, int bot){
	int wmid = (l + r) / 2;
	int hmid = (top + bot) / 2;
	if(bot - top == 2){
		arr[top][wmid] = '*';
		arr[top+1][wmid-1] = '*', arr[top+1][wmid+1] = '*';  
		for(int i = l; i < r; i++)
			arr[bot][i] = '*';
	}
	else{
		star((l + wmid) / 2 + 1 , (wmid + r) / 2, top, hmid);
		star(wmid + 1, r, hmid + 1, bot);
		star(l, wmid, hmid + 1, bot);
	}
}

int main(void){
	cin >> N;

	star(1, N*2, 1, N);

	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N*2; j++){
			if(arr[i][j] == '*')
				cout << '*';
			else
				cout << ' ';
		}
		cout << '\n';
	}
}
