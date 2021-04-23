#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define PLL pair<ll,ll>
#define PD pair<double,double>
#define X first
#define Y second

ll ccw(PLL a, PLL b, PLL c) {
	ll ret = a.X*b.Y - b.X*a.Y + b.X*c.Y - c.X*b.Y + c.X*a.Y - a.X*c.Y;
	if(ret < 0) return -1;
	if(!ret) return 0;
	return 1;
}
PD solve(PD a, PD b, bool &chk){
	if(b.X-a.X != 0) {
		double alpha = (b.Y-a.Y) / (b.X-a.X);
		double beta = a.Y - alpha*a.X;
		return {alpha, beta};
	}
	chk = true;
	return {0, 0};
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
		if(a <= d && b >= c) {
			cout << 1 << '\n';
			if(a != d && b == c) 
				cout << b.X << ' ' << b.Y;
			else if(a == d && b != c)
				cout << a.X << ' ' << a.Y;
			else if(b == d && a != c) {
				if(ccw(a,b,c) != ccw(a,b,d))
					cout << b.X << ' ' << b.Y;
			}
			else if(a == c && b != d) {
				if(ccw(a,b,c) != ccw(a,b,d))
					cout << a.X << ' ' << a.Y;
			}
		}
		else
			cout << 0;
	}
	else if(ab <= 0 && cd <= 0) {
		cout << 1 << '\n';
		bool chk1 = false, chk2 = false;
		PD L1 = solve(a, b, chk1);
		PD L2 = solve(c, d, chk2);
		cout << fixed;
		cout.precision(10);
		if(chk1) 
			cout << a.X << ' ' << L2.X*a.X + L2.Y;
		else if(chk2)
			cout << c.X << ' ' << L1.X*c.X + L1.Y;
		else {
			PD res = solve(L1, L2, chk1);
			cout << -res.X << ' ' << res.Y;
		}
	}
	else
		cout << 0;
}
