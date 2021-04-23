#include <bits/stdc++.h>

using namespace std;

const int MN = 1001010;
const int INF = 1e9;

vector<int> arr;
void Post(int l, int r) {
	if(l == r) 
		cout << arr[l] << '\n';
	if(l >= r) return;

	int cur = l;	
	int pivot = l;
	for(int i = l+1; i <= r; i++) {
		if(arr[cur] > arr[i])
			pivot = i;
	}

	Post(l+1, pivot);
	Post(pivot+1, r);
	cout << arr[cur] << '\n';
}
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int a;
	while(cin >> a) 
		arr.push_back(a);		

	Post(0, arr.size()-1);
}
