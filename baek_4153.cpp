#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);

	int a, b, c;
	while(1) {
		cin >> a >> b >> c;
		if(a == 0 && b == 0 && c == 0)
			break;
		
		if(b < c)
			swap(b, c);
		if(a < b)
			swap(a, b);

		if(a * a == b * b + c * c)
			cout << "right" << '\n';
		else
			cout << "wrong" << '\n';
	}
}
