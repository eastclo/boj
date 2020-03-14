#include <iostream>
#include <algorithm>
#include <vector>

#define ll long long

using namespace std;

const int MN = 500101;

ll seg[MN*4];
int A[MN];
vector<pair<int,int>> com;

ll update(int idx, ll val, int n, int l, int r){
	if(idx < l || r < idx) return seg[n];
	if(l == r) return seg[n] = val;
	int mid = (l+r)/2;
	return seg[n] = update(idx, val, n*2, l, mid) + update(idx, val, n*2+1, mid+1, r);
}

ll query(int L, int R, int n, int l, int r){
	if(r < L || R < l) return 0;
	if(L <= l && r <= R) return seg[n];
	int mid = (l+r)/2;
	return query(L, R, n*2, l, mid) + query(L, R, n*2+1, mid+1, r);
}

int main(void){
	int N;  cin >> N;
	for(int i = 1; i <= N; i++){
		cin >> A[i];
		com.push_back({A[i],i});
	}
	//좌표 압축
	sort(com.begin(), com.end());
	int P = 1;
	for(int i = 0; i < com.size(); i++){
		if(i && com[i-1].first != com[i].first) P++;
		A[com[i].second] = P;
	}

	ll res = 0;
	for(int i = 1; i <= N; i++){
		update(A[i], 1, 1, 1, N);
		res += query(A[i]+1, N, 1, 1, N);
	}

	cout << res << '\n';
}
