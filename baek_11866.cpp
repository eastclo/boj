#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N, K;	cin >> N >> K;
	queue<int> q;
	for(int i = 1; i<= N; i++)
		q.push(i);

	cout << '<';
	int cnt = 0;
	while(1) {
		cnt++;
		if(q.size() == 1) {
			cout << q.front();
			break;
		}
		if(cnt % K != 0) {
			q.push(q.front());
			q.pop();
		}
		else {
			cout << q.front() << ", ";
			q.pop();
		}
	}
	cout << '>';
}
