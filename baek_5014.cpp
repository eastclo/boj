#include <bits/stdc++.h>

using namespace std;
#define P pair<int,int>
#define X first
#define Y second

const int MN = 1001010;

bool visited[MN];
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int F, S, G, U, D;	cin >> F >> S >> G >> U >> D;

	queue<P> q;
	q.push({0, S});
	visited[S] = true;
	while(!q.empty()) {
		P top = q.front();	q.pop();
		int dep = top.X;
		int n = top.Y;
		if(n == G) {
			cout << dep;	return 0;
		}
		if(n-D >= 1 && !visited[n-D]) {
			visited[n-D] = true;
			q.push({dep+1, n-D});
		}
		if(n+U <= F && !visited[n+U]) {
			visited[n+U] = true;
			q.push({dep+1, n+U});
		}
	}
	cout << "use the stairs";
}
