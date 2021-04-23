#include <bits/stdc++.h>

using namespace std;

const int MN = 10101;

int arr[MN];
int st, en, sum, res;
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N, M;	cin >> N >> M;
	for(int i = 0; i < N; i++) 
		cin >> arr[i];

	sum = arr[0];
	while(en < N){
		if(sum == M) {
			res++;
			sum -= arr[st++];	
		}
		else if(sum > M) 
			sum -= arr[st++];	
		else 
			sum += arr[++en];
	}
	cout << res;
}