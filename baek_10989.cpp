#include <bits/stdc++.h>

using namespace std;
const int MN = 10101;

int arr[MN];
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);

	int N;	cin >> N;
	while(N--) {
		int num;	cin >> num;
		arr[num]++;
	}
	for(int i = 0; i < MN; i++)
		while(arr[i]--)
			cout << i << '\n';
}
