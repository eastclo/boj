#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	string N;	cin >> N;
	sort(N.begin(), N.end(), greater<int>());
	cout << N;
}
