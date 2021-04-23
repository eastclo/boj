#include <bits/stdc++.h>

using namespace std;
#define P pair<int,int>
#define X first
#define Y second

const int MN = 1010101;

vector<int> g[MN];
int prv[MN];
bool visited[MN];
void solve(int n) {
	if(n == 0) return;
	solve(prv[n]);
	cout << n << ' ';
}

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int cur = 1;
	int num = 2;
	while(cur < MN && num < MN) {
		while(g[cur].size() != 6) {
			if(!g[cur].empty()) {
				g[num].push_back(g[cur].back());
				g[g[cur].back()].push_back(num);
			}
			g[cur].push_back(num);
			g[num++].push_back(cur);
		}
		int a = g[cur].front(), b = g[cur].back();


		reverse(g[a].begin(), g[a].end());
		g[b].push_back(a);
		g[a].push_back(b);
		
		cur++;
	}

	int a, b;	cin >> a >> b;
		
	queue<P> q; 
	q.push({0, a});
	visited[a] = true;
	while(!q.empty()) {
		P top = q.front();	q.pop();
		int depth = top.X;
		int n = top.Y;
		if(n == b) {
			solve(n);
			return 0;
		}

		for(int nxt : g[n]) {
			if(!visited[nxt]) {
				visited[nxt] = true;
				prv[nxt] = n;
				q.push({depth+1, nxt});
			}
		}
	}
}
