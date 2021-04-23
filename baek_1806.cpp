#include <bits/stdc++.h>

using namespace std;

const int MN = 100101;
const int INF = 1e9;

int arr[MN], st, en, sum;
int len = INF;
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N, S;	cin >> N >> S;
	for(int i = 0; i < N; i++)
		cin >> arr[i];

	sum = arr[0];
	while(en < N) {
		if(sum < S)
			sum += arr[++en];
		else {
			len = min(len, en-st+1);
			sum -= arr[st++];
		}
	}

	if(len != INF)
		cout << len;
	else
		cout << 0;

}
