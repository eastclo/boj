#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int T;	cin >> T;
	while(T--) {
		int N, M;	cin >> N >> M;
		queue<pair<int,int>> q;
		vector<int> arr;
		for(int i = 0; i < N; i++) {
			int a;	cin >> a;
			q.push({i, a});
			arr.push_back(a);
		}
		sort(arr.begin(), arr.end(), greater<int>());
		for(int i = 0; i < arr.size(); i++) {
			while(!q.empty()) {
				auto prio = q.front();
				if(prio.second == arr[i]) {
					if(prio.first == M) 
						cout << i+1 << '\n';	
					q.pop();
					break;
				}
				else {
					q.push(q.front());
					q.pop();
				}
			}
		}
	}
}
