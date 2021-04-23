#include <bits/stdc++.h>

using namespace std;
const int MN = 21;
const int INF = 1e9;

int arr[MN][MN], c[MN], res = INF, N;
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N;
	for(int i = 0; i < N; i++) 
		for(int j = 0; j < N; j++) 
			cin >> arr[i][j];

	for(int i = 0; i < N/2; i++)
		c[i] = 1;
	for(int i = N/2; i < N; i++)
		c[i] = 0;

	do {
		int ssum = 0, lsum = 0;
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				if(c[i] && c[j])
					ssum += arr[i][j];
				else if(!c[i] && !c[j])
					lsum += arr[i][j];
			}
		}

		res = min(res, abs(ssum-lsum));
	} while(prev_permutation(c, c + N));
	cout << res;
}
