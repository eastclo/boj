#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define P pair<int,int>
#define PLL pair<ll,ll>
#define X first
#define Y second

const int MN = 26;
const int INF = 1e9;

int cnt[MN];
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	string s;	cin >> s;
	for(char a : s){
		if(a > 'Z')
			cnt[a-'a']++;
		else
			cnt[a-'A']++;
	}

	bool ch = false;
	int maxi = -1;
	char res;
	for(int i = 0; i < MN; i++) {
		if(maxi < cnt[i]) {
			maxi = cnt[i];
			ch = false;
			res = i+'A';
		}
		else if (maxi == cnt[i])
			ch = true;
	}
	if(ch)
		cout << '?';
	else
		cout << res;
}
