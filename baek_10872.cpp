#include <bits/stdc++.h>

using namespace std;
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N;	cin >> N;
	int res = 1;
	while(N)
		res *= N--;
	cout << res;
}
