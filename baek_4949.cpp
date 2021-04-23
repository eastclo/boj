#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	while(1) {
		bool err = false;
		vector<int> st;
		string s;
		getline(cin, s);
		if(s == ".")
			break;

		for(int i = 0; i < s.size(); i++) {
			if(s[i] == '(')
				st.push_back(1);
			else if(s[i] == '[')
				st.push_back(2);
			else if(s[i] == ')') {
				if(err || st.empty() || st.back() != 1 )
					err = true;
				else
					st.pop_back();
			}
			else if(s[i] == ']') {
				if(err || st.empty() || st.back() != 2)
					err = true;
				else
					st.pop_back();
			}
		}
		if(err || !st.empty())
			cout << "no\n";
		else
			cout << "yes\n";
	}
}
