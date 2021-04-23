#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int a, b;
	while(1) {
		cin >> a >> b;
		if(!a && !b)
			break;
		if(a < b && b % a == 0)
			cout << "factor\n";
		else if(a > b && a % b == 0)
			cout << "multiple\n";
		else
			cout << "neither\n";
	}
}
