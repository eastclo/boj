#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	string s;	cin >> s;
	int res = 0;
	for(int i = 0; i < s.size(); i++) {
		string k = s.substr(i,2);
		if(k=="c="||k=="c-"||k=="d-"||k=="lj"||k=="nj"||k=="s="||k=="z=")i++;
		else if(k=="dz" && s[i+2]=='=')i+=2;
		res++;
	}
	cout << res;
}
