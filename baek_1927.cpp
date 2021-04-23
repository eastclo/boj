#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N;	cin >> N;
	priority_queue<int, vector<int>, greater<int>> pq;
	for(int i = 0; i < N; i++) {
		int a;	cin >> a;
		if(a)
			pq.push(a);
		else {
			if(pq.empty())
				cout << 0 << '\n';
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
	}
}
