#include <bits/stdc++.h>

using namespace std;
const int MN = 101;
const int INF = 1e9;

int arr[MN];
int gcd(int a, int b) {
	return b ? gcd(b, a%b) : a;
}

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N;	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> arr[i];
	
	sort(arr, arr + N);
	for(int i = 0; i < N-1; i++) 
		arr[i] = arr[i+1]-arr[i];

	int tmp = arr[0];
	for(int i = 1; i < N-1; i++)
		tmp = gcd(tmp, arr[i]);

	vector<int> res;
	for(int i = 1; i * i <= tmp; i++) {
		int num = tmp;
		if(num % i == 0) {
			res.push_back(i);	
			if(i*i != tmp)
				res.push_back(num/i);
		}
	}

	sort(res.begin(), res.end());
	for(int i = 1; i < res.size(); i++)
		cout << res[i] << ' ';
}
