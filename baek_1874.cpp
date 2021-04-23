#include <bits/stdc++.h>

#define push push_back
#define pop pop_back
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int T;	cin >> T;
	int num = 1;
	vector<char> res;
	vector<int> st;
	bool err = false;
	while(T--) {
		int n;	cin >> n;
		if(st.empty()) {
			if(num > n) {
				err = true;
				break;
			}
			else {
				while(num != n) {
					st.push(num++);
					res.push('+');
				}
				st.push(num++);
				res.push('+');
				st.pop();
				res.push('-');
			}
		}
		else if(st.back() < n){
			if(num > n) {
				err = true;
				break;
			}
			else {
				while(num != n) {
					st.push(num++);
					res.push('+');
				}
				st.push(num++);
				res.push('+');
				st.pop();
				res.push('-');
			}
		}
		else {
			while(!st.empty() && st.back() > n) {
				st.pop();
				res.push('-');
			}
			if(st.empty() || st.back() != n) {
				err = true;
				break;
			}
			else if(st.back() == n) {
				st.pop();
				res.push('-');
			}
		}
	}
	if(err)
		cout << "NO";
	else {
		for(char a: res)
			cout << a << '\n';
	}
}
