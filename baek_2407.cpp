#include <bits/stdc++.h>

using namespace std;
const int MN = 101;

string dp[MN][MN];

string add(string a, string b) {
	long long sum = 0;
	string result;
	while (!a.empty() || !b.empty() || sum) {
		if (!a.empty()) {
			sum += a.back() - '0'; 
			a.pop_back(); 
		}

		if (!b.empty()) {
			sum += b.back() - '0';
			b.pop_back();
		}

		result.push_back((sum % 10) + '0');
		sum /= 10;
	}

	reverse(result.begin(), result.end());
	return result;
}

string solve(int n, int m) {
	string &ret = dp[n][m];
	if(m == 0 || m == n)
		return "1";
	if(ret != "")
		return ret;
	return ret = add(solve(n-1, m-1), solve(n-1, m));
}
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N, M;	cin >> N >> M;

	cout << solve(N, M);
}
