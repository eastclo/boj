#include <bits/stdc++.h>

using namespace std;

const int MN = 100101;
const int INF = 2123456789;

int arr[MN];
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N;	cin >> N;
	for(int i = 0; i < N; i++) 
		cin >> arr[i];
	sort(arr, arr + N);

	int st = 0;
	int en = N-1;
	int res = INF;
	int res1, res2;
	while(st < en){
		int sum = arr[st] + arr[en];
		if(sum == 0) {
			res1 = arr[st], res2 = arr[en];
			break;
		}
		int tmp = abs(sum);
		if(res > tmp) {
			res = tmp;
			res1 = arr[st], res2 = arr[en];
		}
		if(sum < 0) 
			st++;
		else 
			en--;
	}
	cout << res1 << ' ' << res2;
}
