#include <bits/stdc++.h>

using namespace std;

const int MN = 100101;

int post[MN];
int in[MN], in_idx[MN];

void dfs(int inl, int inr, int postl, int postr) {
	int cur = postr;
	if(postl == postr)
		cout << post[cur] << ' ';
	if(postl >= postr)
		return;

	cout << post[cur] << ' ';
	int incur = in_idx[post[cur]];
	int lcnt = incur-inl;
	int rcnt = inr-incur;

	dfs(inl, incur-1, postl, postl+lcnt-1);
	dfs(incur+1, inr, postl+lcnt , postr-1);
}

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N;	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> in[i];
		in_idx[in[i]] = i;
	}
	for(int i = 0; i < N; i++) 
		cin >> post[i];

	dfs(0, N-1, 0, N-1);
}
