#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define PLL pair<ll,ll>
#define X first
#define Y second

ll ccw(PLL a, PLL b, PLL c) {
	ll ret = a.X*b.Y - b.X*a.Y + b.X*c.Y - c.X*b.Y + c.X*a.Y - a.X*c.Y;
	if(ret < 0) return -1;
	if(!ret) return 0;
	return 1;
}

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	PLL a, b, c, d;
	cin >> a.X >> a.Y >> b.X >> b.Y;
	cin >> c.X >> c.Y >> d.X >> d.Y;

	ll ab = ccw(a, b, c) * ccw(a, b, d);
	ll cd = ccw(c, d, a) * ccw(c, d, b);
	if(ab == 0 && cd == 0) {
		if(a>b) swap(a, b);
		if(c>d) swap(c, d);
		if(a <= d && b >= c)
			cout << 1;
		else
			cout << 0;
	}
	else if(ab <= 0 && cd <= 0)
		cout << 1;
	else
		cout << 0;
}
