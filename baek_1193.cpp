#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int n;	cin >> n;
	int par = 1, chi = 1, cnt = 1;
	if(n == 1) {
		cout << "1/1";
		return 0;
	}

	for(int i = 1;; i++) {
		if(i % 2)
			par++;
		else
			chi++;

		if(++cnt == n) {
			cout << chi << '/' << par;
			return 0;
		}

		for(int j = 0; j < i; j++) {
			if(i % 2) 
				par--, chi++;			
			else 
				par++, chi--;	
			if(++cnt == n) {
				cout << chi << '/' << par;
				return 0;
			}
		}
	}

}
