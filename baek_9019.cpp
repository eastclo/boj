#include <bits/stdc++.h>

using namespace std;
#define P pair<char,int>
#define X first
#define Y second

const int MN = 10001;
const int MOD = 10000;

bool visited[MN];
P prv[MN];
int N, M;
void solve(int n) {
	if(n==N) return;

	solve(prv[n].Y);
	cout << prv[n].X;
}

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int T;	cin >> T;
	while(T--) {
		cin >> N >> M;
		memset(visited, 0, sizeof(visited));
		memset(prv, 0, sizeof(prv));
		
		queue<int> q;
		q.push(N);
		visited[N] = true;
		prv[N].Y = -1;

		while(!q.empty()) {
			int n = q.front();	q.pop();
			if(n == M) {
				solve(n);
				break;
			}

			int D = (n*2) % MOD;
			if(!visited[D]) {
				visited[D] = true;
				prv[D].Y = n; prv[D].X = 'D';
				q.push(D);
			}
			int S = n-1;
			if(S < 0) S = 9999;
			if(!visited[S]) {
				visited[S] = true;
				prv[S].Y = n; prv[S].X = 'S';
				q.push(S);
			}

			int L, R;
			L = (n%1000)*10 + n/1000;
			R = (n%10)*1000 + n/10;
			if(!visited[L]) {
				visited[L] = true;
				prv[L].Y = n; prv[L].X = 'L';
				q.push(L);
			}
			if(!visited[R]) {
				visited[R] = true;
				prv[R].Y = n; prv[R].X = 'R';
				q.push(R);
			}
		}
		cout << '\n';
	}
}
