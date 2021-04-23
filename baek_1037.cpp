#include <bits/stdc++.h>

using namespace std;
const int MN = 51;

int arr[MN];
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N;	cin >> N;
	for(int i = 0; i < N; i++) 
		cin >> arr[i];
	sort(arr, arr + N);
	cout << arr[0] * arr[N-1];
}	
