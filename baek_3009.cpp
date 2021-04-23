#include <bits/stdc++.h>

using namespace std;

const int MN = 1001;
const int INF = 1e9;

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int a, b, c, d, e, f;	cin >> a >> b >> c >> d >> e >> f;

	if(a == c) 
		cout << e << ' ';	
	else {
		if(a == e)
			cout << c << ' ';
		else
			cout << a << ' ';
	}

	if(b == d) 
		cout << f << ' ';	
	else {
		if(b == f)
			cout << d << ' ';
		else
			cout << b << ' ';
	}
}
