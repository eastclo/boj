#include <bits/stdc++.h>

using namespace std;

const int MN = 1001010;
const int INF = 1e9;

int arr[MN], l, N, a;
int s[MN];
int bt[MN];
vector<int> res;
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> s[i];
		auto idx = lower_bound(arr, arr + l, s[i]);
		if(*idx==0) {
			bt[i] = l;
			l++; 
		}
		else
			bt[i] = idx-arr;
		*idx = s[i];
		
	}
	cout << l << '\n';
	for(int i = N-1; i >= 0 ; i--){
		if(bt[i] == l-1) {
			res.push_back(s[i]);
			l--;
		}
	}	

	for(int i = res.size()-1; i >= 0; i--)
		cout << res[i] << ' ';
}
