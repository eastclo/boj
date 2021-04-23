#include <bits/stdc++.h>

using namespace std;
const int MN = 1;
const int INF = 1e9;

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N, M;	cin >> N >> M;

	deque<int> deq1, deq2;
	for(int i = 1; i <= N; i++) {
		deq1.push_back(i);
		deq2.push_back(i);
	}

	int cur = 1, res = 0;
	for(int i = 0; i < M; i++) {
		int a;	cin >> a;
		int cnt1 = 0, cnt2 = 0;
		for(int j = 0; j < deq1.size(); j++) {
			if(deq1.front() == a)
				break;
			else {
				deq1.push_back(deq1.front());
				deq1.pop_front();
				cnt1++;
			}
		}
		for(int j = 0; j < deq2.size(); j++) {
			if(deq2.front() == a)
				break;
			else {
				deq2.push_front(deq2.back());
				deq2.pop_back();
				cnt2++;
			}
		}
		res += min(cnt1, cnt2);
		deq1.pop_front();
		deq2.pop_front();
	}
	cout << res;
}
