#include <iostream>

using namespace std;

long long A, B, C;
long long pw(long long a, long long n){
	if(n == 1)
		return a % C;
	if(n%2) return pw(a, n-1) * a % C;
	long long tmp = pw(a, n/2);
	return tmp * tmp % C;
}

int main(void){
	cin >> A >> B >> C;

	cout << pw(A,B) << '\n';
}
