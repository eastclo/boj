#include <bits/stdc++.h>

using namespace std;

const int MN = 100101;
const int INF = 2e9;

struct P {
	int x,y;
	bool operator <(const P &a)const {
		if(y == a.y) return x < a.x;
		return y < a.y;
	}
};
P arr[MN];

int dist(P a, P b) {
	int c = a.x-b.x;
	int d = a.y-b.y;
	return c * c + d * d;
}

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N;	cin >> N;

	for(int i = 0; i < N; i++)
		cin >> arr[i].x >> arr[i].y;

	sort(arr, arr + N, [](const P& A, const P& B) { 
			if(A.x == B.x) 
				return A.y < B.y;
			return A.x < B.x;
			});

	set<P> candi = {arr[0], arr[1]};
	int res = dist(arr[0], arr[1]);
	int start = 0;
	for(int i = 2; i < N; i++) {
		P now = arr[i];
		while(start < i) {
			auto p = arr[start];
			int x = now.x - p.x;
			if(x*x > res) {
				candi.erase(p);
				start++;
			} else break;
		}
		int d = (int)sqrt(res)+1;
		P lp = {-100000, now.y-d};
		P rp = {100000, now.y+d};
		auto lower = candi.lower_bound(lp);
		auto upper = candi.upper_bound(rp);
		for(auto it = lower; it != upper; it++) {
			int d = dist(now, *it);
			res = min(res, d);
		}
		candi.insert(now);
	}

	cout << res;
}
