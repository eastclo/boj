#include <bits/stdc++.h>

using namespace std;
const int MN = 1000101;

int arr[MN];
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N;	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> arr[i];
	
	vector<int> st;
	vector<int> res;
	for(int i = N-1; i >= 0; i--) {
		while(!st.empty() && st.back() <= arr[i])
			st.pop_back();

		if(st.empty())
			res.push_back(-1);
		else 
			res.push_back(st.back());
		st.push_back(arr[i]);
	}
	reverse(res.begin(), res.end());
	for(int a: res)
		cout << a << ' ';
}
