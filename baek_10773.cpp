#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	vector<int> arr;
	int N;	cin >> N;
	while(N--) {
		int a;	cin >> a;
		if(a) 
			arr.push_back(a);
		else
			arr.pop_back();
	}
	int res = 0;
	for(int a : arr)
		res += a;
	cout << res;
}
