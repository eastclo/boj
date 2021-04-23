#include <bits/stdc++.h>

using namespace std;
const int MN = 17101;
string s1, s2;

int dp[2][MN];
char prv[MN][MN/4]; //비트연산 
//  0 : copy,  1 : add,  2 : del,  3 : modi

void print_edit(int i, int j)
{
	if(i == 0 && j == 0) 
		return;
	int trace = prv[i][j/4] & (0xC0 >> 2*(j%4)); 
	for(int k = 0; k < 4; k++) {
		if((trace >> 2*k) < 4) {	
			trace >>= 2*k;
			break;
		}
	}

	if(trace == 0) {
		print_edit(i-1, j-1);				
		cout << "c " << s2[j] << '\n';
	}
	else if(trace == 1){
		print_edit(i, j-1);
		cout << "a " << s2[j] << '\n';
	}
	else if(trace == 2) {
		print_edit(i-1, j);
		cout << "d " << s1[i] << '\n';
	}
	else {
		print_edit(i-1, j-1);
		cout << "m " << s2[j] << '\n';
	}
}

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	cin >> s1 >> s2;
	s1 = '0' + s1;
	s2 = '0' + s2;
	for(int j = 1; j < s2.size(); j++) { 
		dp[0][j] = j;
		prv[0][j/4] |= (0x40 >> 2*(j%4));
	}
	for(int i = 1; i < s1.size(); i++) {
		dp[i%2][0] = i;
		prv[i][0] |= 0x80;
		for(int j = 1; j < s2.size(); j++) {
			if(s1[i] == s2[j]) {
				dp[i%2][j] = dp[(i-1)%2][j-1];	
				prv[i][j/4] |= (0x00 >> 2*(j%4));
			}
			else {
				int add = dp[i%2][j-1] + 1;
				int del = dp[(i-1)%2][j] + 1;
				int modi = dp[(i-1)%2][j-1] + 1;
				if(add < del) {
					dp[i%2][j] = add;
					prv[i][j/4] |= (0x40 >> 2*(j%4));
				}
				else {
					dp[i%2][j] = del;
					prv[i][j/4] |= (0x80 >> 2*(j%4));
				}
				if(modi < dp[i%2][j]) {
					dp[i%2][j] = modi;
					prv[i][j/4] |= (0xC0 >> 2*(j%4));
				}
			}
		}
	}

	print_edit(s1.size()-1, s2.size()-1);
}
