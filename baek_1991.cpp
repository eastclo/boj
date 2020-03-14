#include <iostream>
using namespace std;

int N;
char L[200], R[200];

void Pre(char n){
	cout << n;
	if(L[n] != '.') Pre(L[n]);
	if(R[n] != '.') Pre(R[n]);
}

void In(char n){
	if(L[n] != '.') In(L[n]);
	cout << n;
	if(R[n] != '.') In(R[n]);
}

void Post(char n){
	if(L[n] != '.') Post(L[n]);
	if(R[n] != '.') Post(R[n]);
	cout << n;
}



int main(void){
	cin >> N;
	for(int i = 0; i < N; i++){
		char a, b, c;   cin >> a >> b >> c;
		L[a] = b;
		R[a] = c;
	}
	Pre('A');
	cout << '\n';
	In('A');
	cout << '\n';
	Post('A');
	cout << '\n';
	return 0;
}
