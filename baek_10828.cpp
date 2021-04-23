#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	vector<int> st;
	int N;	cin >> N;
	for(int i = 0; i < N; i++) {
		string a; cin >> a;
		if(a == "push") {
			int b;	cin >> b;
			st.push_back(b);
		}
		else if(a == "top"|| a == "pop") {
			if(st.empty())
				cout << -1 << '\n';
			else {
				cout << st.back() << '\n';
				if(a == "pop")
					st.pop_back();
			}
		}
		else if(a == "size")
			cout << st.size() << '\n';
		else 
			cout << st.empty() << '\n';
	}
}