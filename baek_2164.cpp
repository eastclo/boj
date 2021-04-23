#include <bits/stdc++.h>

using namespace std;
const int MN = 1;
const int INF = 1e9;

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N;	cin >> N;
	queue<int> q;
	for(int i = 1; i <= N; i++)
		q.push(i);
	while(!q.empty()) {
		if(q.size() == 1) {
			cout << q.front();
			break;
		}
		q.pop();
		q.push(q.front());
		q.pop();
	}
}
