#include <iostream>

using namespace std;

int gcd(int a, int b){
	return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b){
	return a / gcd(a, b) * b;
}

int main(void){
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	int e, f;
	f = lcm(b, d);
	a *= (f / b);
	c *= (f / d);
	e = a + c;

	int gcdEF = gcd(e, f);
	if (gcdEF!=1){
		e /= gcdEF;
		f /= gcdEF;
	}

	cout << e << ' ' << f << '\n';

}

