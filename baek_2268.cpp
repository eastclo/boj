#include <iostream>
#include <algorithm>

using namespace std;
#define ll long long
const int MN = 1001010;

ll seg[MN*4];

ll update(int idx, int val, int n, int l, int r){
	if(idx < l || r < idx) return seg[n];
	if(l == r) return seg[n] = val;
	int mid = (l + r)/2;
	return seg[n] = update(idx, val, n*2, l, mid) + update(idx, val, n*2+1, mid+1, r);
}

ll query(int L, int R, int n, int l, int r){
	if(r < L || R < l) return 0;
	if(L <= l && r <= R) return seg[n];
	int mid = (l + r)/2;
	return query(L, R, n*2, l, mid) + query(L, R, n*2+1, mid +1, r);
}

int main(void){
	ios::sync_with_stdio(false);    cin.tie(NULL);
	int N, M;       cin >> N >> M;
	while(M--){
		int a, b, c;    cin >> a >> b >> c;
		if(a == 0){
			if(b > c) swap(b, c);
			cout << query(b, c, 1, 1, N) << '\n';
		}
		else{
			update(b, c, 1, 1, N);
		}
	}
}
