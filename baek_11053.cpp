#include <bits/stdc++.h>

using namespace std;

const int MN = 1010;

int arr[MN];
int dp[MN];	//i번째를 반드시 포함했을 때 최대길이.
int main(void){
	int N;	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> arr[i];

	fill(dp, dp + N, 1);
	for(int i = 0; i < N; i++){
		for(int j = 0; j < i; j++){
			if(arr[i] > arr[j]){
				if(dp[i] < dp[j] + 1)
					dp[i] = dp[j] + 1;
			}
		}	
	}
}
