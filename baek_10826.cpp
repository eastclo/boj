#include <bits/stdc++.h>

using namespace std;

string dp[3];
string add(string a, string b) {
	if(a.size() < b.size())
		swap(a, b);
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	string ret;
	int up = 0;
	for(int i = 0; i < b.size(); i++) {
		int sum = a[i]-'0' + b[i]-'0' + up;
		if(sum > 9)
			up = 1, sum -= 10;
		else up = 0;
		ret += (char)(sum+'0');
	}
	for(int i = b.size(); i < a.size(); i++) {
		int sum = a[i]-'0' + up;
		if(sum > 9) 
			up = 1, sum -= 10;
		else up = 0;
		ret += (char)(sum+'0');
	}
	if(up)
		ret += "1";

	reverse(ret.begin(), ret.end());

	return ret;
}

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N;	cin >> N;
	dp[0] = "0";
	dp[1] = "1";
	for(int i = 2; i <= N; i++) 
		dp[i%3] = add(dp[(i-1)%3], dp[(i-2)%3]);
	cout << dp[N%3];
}
