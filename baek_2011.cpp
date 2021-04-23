#include <bits/stdc++.h>

using namespace std;

const int MN = 5010;
const int MOD = 1e6;

string arr;
int dp[MN];
int solve(int i, int last) {
	int &ret = dp[i];
	if(arr[i] == '0')
		return 0;
	else if(i == last)
		return 1;
	else if(i + 1 == last) {
		if((arr[i] == '1' || (arr[i] == '2' && arr[i+1] <= '6')) && arr[i+1] != '0')
			return 2;
		else 
			return 1;
	}
	if(ret != -1)
		return ret;

	ret = 0;
	if(arr[i] == '1' || (arr[i] == '2' && arr[i+1] <= '6')) 
		ret = solve(i+1, last) + solve(i+2, last);
	else
		ret = solve(i+1, last);
	
	return ret % MOD;
}

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	cin >> arr;
	memset(dp, -1, sizeof(dp));
	for(int i = 0; i < arr.size()-1; i++) {
		if(arr[i+1] == '0' && arr[i] > '2') {
			cout << 0;
			return 0;
		}
	}
	
	cout << solve(0, arr.size()-1);
}
