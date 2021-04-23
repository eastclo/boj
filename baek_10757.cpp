#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	string a, b;	cin >> a >> b;

	if(a.length() < b.length()) 
		swap(a, b);

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	vector<int> res;

	int carr = 0, sum = 0;
	for(int i = 0; i < b.length(); i++) {
		sum = a[i] + b[i] + carr - '0' - '0';	
		carr = sum / 10;
		sum -= carr * 10;

		res.push_back(sum);
	}

	for(int i = b.length(); i < a.length(); i++) {
		sum = a[i] + carr - '0';	
		carr = sum / 10;
		sum -= carr * 10;

		res.push_back(sum);
	}
	if(carr == 1)
		res.push_back(carr);

	reverse(res.begin(), res.end());
	
	for(int out : res)
		cout << out;
}
