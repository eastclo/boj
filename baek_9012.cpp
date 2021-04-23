#include <bits/stdc++.h>

using namespace std;
int main()
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int T;	cin >> T;
	while(T--) {
		vector<int> st;
		string a;	cin >> a;
		bool check = false;
		for(char ch : a) {
			if(ch == '(')
				st.push_back(1);
			else {
				if(st.empty()) {
					check = true;
					break;
				}
				else
					st.pop_back();
			}
		}
		if(!st.empty() || check)
			cout << "NO\n";
		else
			cout << "YES\n";
	}
}
