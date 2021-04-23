#include <bits/stdc++.h>

using namespace std;
#define P pair<int,int>
#define X first
#define Y second

const int MN = 100101;

int prv[MN];
bool visited[MN];
void solve(int n) {
	if(n == -1)	
		return;

	solve(prv[n]);
	cout << n << ' ';
}
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N, K;	cin >> N >> K;

	queue<P> q;
	q.push({0,N});
	prv[N] = -1;
	visited[N] = true;

	while(!q.empty()) {
		P top = q.front();	q.pop();
		int depth = top.X;
		int n = top.Y;

		if(n == K) {
			cout << depth << '\n';
			solve(n);
			return 0;
		}

		int next1 = n*2;
		int next2 = n+1;
		int next3 = n-1;
		
		if(0 <= next1 && next1 < MN && !visited[next1]) {
			visited[next1] = true;
			prv[next1] = n;
			q.push({depth+1, next1});
		}
		if(0 <= next2 && next2 < MN && !visited[next2]) {
			visited[next2] = true;
			prv[next2] = n;
			q.push({depth+1, next2});
		}
		if(0 <= next3 && next3 < MN && !visited[next3]) {
			visited[next3] = true;
			prv[next3] = n;
			q.push({depth+1, next3});
		}
	}
}
