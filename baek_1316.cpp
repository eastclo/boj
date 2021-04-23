#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N;	cin >> N;
	int res = 0;
	while(N--) {
		string s;	cin >> s;
		int alpha[26] = {0,};
		char prev = s[0];
		alpha[prev-'a']++;
		bool check = true;
		for(int i = 1; i < s.size(); i++) {
			if(prev != s[i]) {
				if(alpha[s[i]-'a'] == 0) {
					prev = s[i];
					alpha[s[i]-'a']++;
				}
				else
					check = false;
			}
		}
		if(check) res++;
	}
	cout << res;
}
