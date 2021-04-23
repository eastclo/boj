#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N;	cin >> N;
	priority_queue<int> bpq;
	priority_queue<int,vector<int>,greater<int>> spq;
	for(int i = 0; i < N; i++) {
		int a;	cin >> a;
		if(i%2){
			if(bpq.top() < a)
				spq.push(a);
			else {
				int tmp = bpq.top();
				bpq.pop();
				bpq.push(a);
				spq.push(tmp);
			}
		}
		else {
			if(bpq.empty() || spq.top() > a)
				bpq.push(a);
			else {
				int tmp = spq.top();
				spq.pop();
				spq.push(a);
				bpq.push(tmp);
			}
		}
		cout << bpq.top() << '\n';
	}
}
