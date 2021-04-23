#include <bits/stdc++.h>

using namespace std;
#define P pair<int,int>
#define X first
#define Y second

const int MN = 27;

char L[MN], R[MN];
void Post(char n) {
	if(n == 0) return;
	cout << n;
	Post(L[n-'A']);
	Post(R[n-'A']);
}

void In(char n) {
	if(n == 0) return;
	In(L[n-'A']);
	cout << n;
	In(R[n-'A']);
}

void Pre(char n) {
	if(n == 0) return;
	Pre(L[n-'A']);
	Pre(R[n-'A']);
	cout << n;
}

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N;	cin >> N;
	for(int i = 0; i < N; i++) {
		char a, b, c;	cin >> a >> b >> c;
		if(b != '.') L[a-'A'] = b;
		if(c != '.') R[a-'A'] = c;
	}

	Post('A'); cout << '\n';
	In('A'); cout << '\n';
	Pre('A');
}
