#include <bits/stdc++.h>

using namespace std;

const int MN = 100101;

int arr[MN];
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N;	cin >> N;
	for(int i = 0; i < N; i++) 
		cin >> arr[i];
	int X;	cin >> X;
	sort(arr, arr + N);

	int st = 0;
	int en = N-1;
	int res = 0;
	while(st < en){
		int sum = arr[st] + arr[en];
		if(sum == X) {
			res++;
			st++, en--;	
		}
		else if(sum < X)
			st++;
		else
			en--;
	}
	cout << res;
}
