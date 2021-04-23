#include <bits/stdc++.h>

using namespace std;
const int MN = 1;
const int INF = 1e9;

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int T;	cin >> T;
	while(T--) {
		string input;	cin >> input;
		int N;	cin >> N;
		deque<int> deq;
		char tmp;	cin >> tmp;
		for(int i = 0; i < N; i++) {
			int a; char tmp2;	cin >> a >> tmp2;
			deq.push_back(a);
		}
		if(N == 0) 
			cin >> tmp;

		bool err = false;
		int rev = 1;
		for(char a: input) {
			if(a=='R') {
				if(!deq.empty())
					rev *= -1;
			}
			else{
				if(!deq.empty()) {
					if(rev == 1)
						deq.pop_front();
					else
						deq.pop_back();
				}
				else {
					err = true;
					break;
				}
			}
		}
		if(err)
			cout << "error\n";
		else {
			cout << '[';
			if(!deq.empty()) {
				if(rev == 1) {
					cout << deq.front();
					deq.pop_front();
				}
				else {
					cout << deq.back();
					deq.pop_back();
				}
			}
			while(!deq.empty()) {
				if(rev == 1) {
					cout << ',' << deq.front();
					deq.pop_front();
				}
				else {
					cout << ',' << deq.back();
					deq.pop_back();
				}
			}
			cout << "]\n";
		}
	}
}
