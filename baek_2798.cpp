#include <bits/stdc++.h>

using namespace std;
const int MN = 101;
const int INF = 1e9;

int arr[MN];
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N, M;	cin >> N >> M;
	for(int i = 0; i < N; i++) 
		cin >> arr[i];

	int res = 0;
	for(int i = 0; i < N-2; i++){
		for(int j = i+1; j < N-1; j++){
			for(int k = j+1; k < N; k++){
				int tmp = arr[i] + arr[j] + arr[k];
				if(tmp <= M && res < tmp)
					res = tmp;
			}
		}
	}

	cout <<  res;
}
