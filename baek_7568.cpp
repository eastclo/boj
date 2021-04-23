#include <bits/stdc++.h>

using namespace std;
const int MN = 51;
const int INF = 1e9;

vector<pair<int,int>> arr;
int res[MN];
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N;	cin >> N;
	for(int i = 0; i < N; i++) {
		int a, b;	cin >> a >> b;
		arr.push_back({a, b});
	}

	for(int i = 0; i < N; i++) {
		int cnt = 0;
		for(int j = 0; j < N; j++) {
			if(i == j) continue;
			if(arr[i].first < arr[j].first && arr[i].second < arr[j].second)
				cnt++;
		}
		cout << cnt + 1 << ' ';
	}
}
