#include <bits/stdc++.h>

using namespace std;
#define P pair<int,int>
#define X first
#define Y second

const int MN = 101;

P arr[MN];
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N, L, K;	cin >> N >> L >> K;
	for(int i = 0; i < N; i++)
		cin >> arr[i].Y >> arr[i].X;
	sort(arr, arr + N);

	int cnt = 0, res = 0;
	for(int i = 0; i < N; i++) {
		if(arr[i].X <= L && cnt < K) {
			cnt++;
			res += 140;
		}
		else if(arr[i].Y <= L && cnt < K) {
			cnt++;
			res += 100;
		}
	}
	cout << res;
}
