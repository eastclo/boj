#include <bits/stdc++.h>

using namespace std;
#define ll long long
const ll MN = 5020;
const ll INF = 1e18;

ll arr[MN], dp[MN][MN], ssum[MN], A[MN][MN];
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	ll T;	cin >> T;
	while(T--) {
		ll N;	cin >> N;
		for(ll i = 1; i <= N; i++) {
			cin >> arr[i];
			ssum[i] = arr[i] + ssum[i-1];
		}
		for(ll i = 0; i < N; i++)
			A[i][i+1] = i+1; //A[i][j]: dp[i][j]가 최소값을 만족하는 k값
	
		for(ll n = 2; n <= N; n++) { 
			//1에서 2처럼 간격 하나짜리를 구해야 하기에 dp정의에 의해 2부터(dp[0][2])
			for(ll i = 0, j = i+n; j <= N; i++, j++) {
				dp[i][j] = INF; //dp[i][j]: i+1부터 j까지의 최소값
				for(ll k = A[i][j-1]; k <= A[i+1][j]; k++) {
					ll min = dp[i][k] + dp[k][j] + ssum[j] - ssum[i];
					if(dp[i][j] > min) {
						dp[i][j] = min;
						A[i][j] = k;
					}
				}
			}
		}
		cout << dp[0][N] << '\n';
	}
}
