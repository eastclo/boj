#include <bits/stdc++.h>

using namespace std;
#define P pair<int,int>
#define x first
#define y second

int ccw(P a, P b, P c) {
	int ret = a.x*b.y - b.x*a.y + b.x*c.y - c.x*b.y + c.x*a.y - a.x*c.y;
	if(ret > 0) return 1;
	else if (!ret) return 0;
	else return -1;
}

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	P a, b, c;	cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
	cout << ccw(a, b, c);
}
