#include <bits/stdc++.h>

using namespace std;
#define P pair<int,int>
#define X first
#define Y second

const int MN = 1001;

int dp[MN][MN];
P prv[MN][MN];

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	string s1, s2;	cin >> s1 >> s2;
	s1 = ' ' + s1;
	s2 = ' ' + s2;

	for(int i = 1; i < s1.size(); i++) {
		for(int j = 1; j < s2.size(); j++) {
			if(s1[i] == s2[j]) {
				dp[i][j] = dp[i-1][j-1] + 1;
				prv[i][j] = make_pair(i-1,j-1);
			}
			else {
				if(dp[i][j-1] < dp[i-1][j]) {
					dp[i][j] = dp[i-1][j];
					prv[i][j] = make_pair(i-1,j);
				}
				else {
					dp[i][j] = dp[i][j-1];
					prv[i][j] = make_pair(i,j-1);
				}
			}
		}
	}

	int i = s1.size()-1, j = s2.size()-1;
	int res = dp[i][j];
	cout << res << '\n';
	vector<char> res2;
	while(res){
		int ni = prv[i][j].X;
		int nj = prv[i][j].Y;
		if(i - ni == 1 && j - nj == 1) {
			res2.push_back(s1[i]);
			res--;
		}
		i = ni;
		j = nj;
	}
	reverse(res2.begin(), res2.end());
	for(char a : res2)
		cout << a;
}
