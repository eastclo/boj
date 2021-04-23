#include <bits/stdc++.h>

using namespace std;

const int MN = 10101;

int L[MN], R[MN];
vector<int> level[MN];
int p[MN];
int col;

int find(int n){
	if(p[n]) return n = find(p[n]);
	return n;
}

void In(int node, int depth){
	if(L[node] != -1) In(L[node], depth + 1);
	level[depth].push_back(++col);
	if(R[node] != -1) In(R[node], depth + 1);
}

int main(void){
	int N;  cin >> N;
	for(int i = 0; i < N; i++){
		int num, a, b;  cin >> num >> a >> b;
		L[num] = a, R[num] = b;
		if(a != -1)
			p[a] = num;
		if(b != -1)
			p[b] = num;
	}
	int rt = find(1);
	In(rt, 1);

	int res = 1, res2 = 1;
	for(int i = 1; level[i].size > 0; i++){
		int a = level[i][0], b = level[i].back();
		int wth = b - a + 1;
		if(res2 < wth){
			res = i, res2 = wth;
		}
	}

	cout << res << ' ' << res2 << '\n';
}
