#include <bits/stdc++.h>

using namespace std;
const int MN = 1;
const int INF = 1e9;

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

long long lcm(int a, int b)
{
	return a * b / gcd(a,b);
}

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int T;	cin >> T;
	while(T--) {
		int a, b;	cin >> a >> b;
		cout << lcm(a, b) << '\n'; 	
	}
}
