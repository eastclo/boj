#include <bits/stdc++.h>

using namespace std;

string s1, s2, s3;
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	cin >> s1 >> s2;
	
	int len = s2.size();
	for(int i = 0; i < s1.size(); i++) {
		s3 += s1[i];
		if(s3.size() >= len) 
			if(s3.substr(s3.size()-len, len) == s2) 
				s3.erase(s3.size()-len, len);
	}
	if(s3.empty())
		cout << "FRULA";
	else
		cout << s3;
}
