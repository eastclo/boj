#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);

	int T;	cin >> T;
	while(T--) {
		int x1, y1, r1, x2, y2, r2;	cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		if(r1 < r2) {
			swap(x1,x2); swap(y1,y2); swap(r1,r2);
		}

		int dist2 = (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2);
		int ar = (r1 + r2) * (r1 + r2);
		int sr = (r1 - r2) * (r1 - r2);

		if(x1 == x2 && y1 == y2 && r1 == r2) 
			cout << -1;
		else if (dist2 < r1*r1) {
			if(dist2 < sr)
				cout << 0;
			else if( dist2 == sr)
				cout << 1;
			else
				cout << 2;
		}
		else {
			if(dist2 == ar)
				cout << 1;
			else if(dist2 < ar)
				cout << 2;
			else
				cout << 0;
		}
		cout << '\n';
	}
}
