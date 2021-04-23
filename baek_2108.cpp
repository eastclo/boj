#include <bits/stdc++.h>

using namespace std;
const int MN = 500101;
const int INF = 1e9;

int arr[MN];
int num[8001];
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N;	cin >> N;
	double res;

	for(int i = 0; i < N; i++) {
		cin >> arr[i];
		res += arr[i];
		num[arr[i]+4000]++;
	}
	res /= N;

	cout << fixed;
	cout.precision(0);
	cout << res << '\n';

	sort(arr, arr + N);
	cout << arr[N/2] << '\n';
	
	int mcnt = 0;
	for(int i = 0; i < 8001; i++) {
		if(mcnt > num[i]) continue;
		mcnt = num[i];
	}

	vector<int> res2;
	for(int i = 0; i < 8001; i++) {
		if(mcnt == num[i])
			res2.push_back(i-4000);
	}

	sort(res2.begin(), res2.end());
	if(res2.size() > 1)
		cout << res2[1] << '\n';
	else
		cout << res2[0] << '\n';
	
	cout << arr[N-1] - arr[0];
}
