#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	queue<int> q;
	int N;	cin >> N;
	while(N--) {
		string a;	cin >> a;
		if(a == "push") {
			int b;	cin >> b;
			q.push(b);
		}
		else if(a == "pop") {
			if(!q.empty()) {
				cout << q.front() << '\n';
				q.pop();
			}
			else
				cout << "-1\n";
		}
		else if(a == "size") 
			cout << q.size() << '\n';
		else if(a == "empty") 
			cout << q.empty() << '\n';
		else if(a == "front") {
			if(q.empty())
				cout << "-1\n";
			else
				cout << q.front() << '\n';
		}
		else {
			if(q.empty())
				cout << "-1\n";
			else
				cout << q.back() << '\n';
		}
					
	}
}
