#include <bits/stdc++.h>

using namespace std;
const int MN = 101;

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N;	cin >> N;
	string a;	cin >> a;
	int res = 0;
	for(char b : a) {
		res += b - '0';
	}
	cout << res;
}
