#include <bits/stdc++.h>

using namespace std;
#define ll long long

const int MN = 300101;
const ll INF = 9e18;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

ll a, b, c, g, mx;
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N;	cin >> N;
	bool chk = true;
	for(int i = 1; i <= N; i++) {
		cin >> a >> b;	
		if(a < 0 && b != 0)
			chk = false;

		if(c < -a) {
			mx = max(mx, b);
			g = gcd(b-a-c, g);
		}
		else if(c + a != b){
			cout << -1;
			return 0;
		}
		c = b;
	}

	if(chk) {
		cout << 1;
		return 0;
	}

	if(g == 0) {
		cout << 1;
		return 0;
	}

	if(g != 1 && mx < g)
		cout << g;
	else
		cout << -1;
}
