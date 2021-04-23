#include <bits/stdc++.h>

using namespace std;
const int MN = 100101;
#define P pair<int,int>

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N;	cin >> N;
	priority_queue<P,vector<P>, greater<P>> pq;
	for(int i = 0; i < N; i++) {
		int a;	cin >> a;
		if(a == 0) {
			if(pq.empty())
				cout << 0 << '\n';
			else {
				P top = pq.top();
				if(!top.second)
					cout << top.first*-1 << '\n';
				else
					cout << top.first << '\n';
				pq.pop();
			}
		}
		else if(a < 0)
			pq.push({a*-1, 0});
		else
			pq.push({a, 1});
	}
	
}
