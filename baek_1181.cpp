#include <bits/stdc++.h>

using namespace std;
const int MN = 20101;
string arr[MN];
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N;	cin >> N;
	for(int i = 0; i < N; i++) 
		cin >> arr[i];

	sort(arr, arr + N, [](string a, string b) {
			if(a.size() < b.size())
				return true;
			else if(a.size() > b.size())
				return false;
			else
				return a < b;
			});
	for(int i = 0; i < N; i++) {
		if(arr[i] == arr[i+1]) continue;
		cout << arr[i] << '\n';
	}
}
