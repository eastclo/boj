#include <bits/stdc++.h>

using namespace std;

const int MN = 500101;

bool sieve[MN];
int arr[51];
int cnt[MN];
long long dp[MN];

int main(void)
{
	sieve[0] = true;	sieve[1] = true;
	for(int p = 2; p * p < MN; p++){
		if(sieve[p]) continue;	
		for(int i = p * p; i < MN; i += p)
			sieve[i] = true;
	}

	int N;	cin >> N;
	for(int i = 1; i <= N; i++) {
		cin >> arr[i]; 
		cnt[arr[i]]++;
	}

	sort(arr + 1, arr + N + 1);
	dp[0] = 1;

	for(int i = cnt[0] + 1; i <= N; i++){
		for(int j = MN-1; j >= 0; j--){
			if(dp[j] != 0){
				for(int k = 1; k <= cnt[arr[i]] ; k++)
					dp[j+arr[i]*k] += dp[j];
			}
		}
		i += cnt[arr[i]]-1;
	}

	long long res = 0;
	for(int i = 0; i < MN; i++)
		if(!sieve[i])
			res += dp[i];

	cout << res*(cnt[0]+1) << '\n';
}
