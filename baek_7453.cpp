#include <bits/stdc++.h>

using namespace std;

vector<int> A, B, C, D;
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N;	cin >> N;
	for(int i = 0; i < N; i++) {
		int a, b, c, d;	cin >> a >> b >> c >> d;
		A.push_back(a);
		B.push_back(b);
		C.push_back(c);
		D.push_back(d);
	}

	vector<int> left;
	for(int a : A) 
		for(int b : B)
			left.push_back(a+b);
	sort(left.begin(), left.end());
	long long res = 0;
	for(int c : C) {
		for(int d : D) {
			auto hi = upper_bound(left.begin(), left.end(), -(c + d));
			auto lo = lower_bound(left.begin(), left.end(), -(c + d));
			res += hi - lo;
		}
	}
	cout << res;
}
