#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);

	int x, y, w, h;	cin >> x >> y >> w >> h;

	int res = INF;

	res = min(res, y);
	res = min(res, x);
	res = min(res, h - y);
	res = min(res, w - x);
	cout << res;
}
