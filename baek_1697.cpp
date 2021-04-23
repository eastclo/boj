#include <bits/stdc++.h>

using namespace std;
#define P pair<int,int>
#define X first
#define Y second

const int MN = 100101;

bool visited[MN];
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N, K;	cin >> N >> K;
	if(N == K) {
		cout << 0;
		return 0;
	}

	queue<P> q;
	q.push({N,0});
	visited[N] = true;
	while(!q.empty()) {
		auto top = q.front();	q.pop();
		int n = top.X;

		int next1 = n-1;
		int next2 = n+1;
		int next3 = n*2;
		if(next1 == K || next2 == K || next3 == K) {
			cout << top.Y+1;
			return 0;
		}

		if(0 <= next1 && next1 < MN) {
			if(!visited[next1]) {
				q.push({next1, top.Y+1});
				visited[next1] = true;
			}
		}
		if(0 <= next2 && next2 < MN) {
			if(!visited[next2]) {
				q.push({next2, top.Y+1});
				visited[next2] = true;
			}
		}
		if(0 <= next3 && next3 < MN) {
			if(!visited[next3]) {
				q.push({next3, top.Y+1});
				visited[next3] = true;
			}
		}
	}
}
