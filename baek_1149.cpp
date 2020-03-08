#include <iostream>
#include <algorithm>

using namespace std;

int cost[1000][3];
int dp[1000][3];

int main(void){
	int N;	cin >> N;

	for(int i = 0; i < N; i++)
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];

	dp[0][0] = cost[0][0];
	dp[0][1] = cost[0][1];
	dp[0][2] = cost[0][2];

	for(int i = 0; i < N; i++){
/*		for(int c = 0; c < 3; c++){
			dp[i][c] = 1e9;
			for(int prvc = 0; prvc < 3; prvc++){
				if(c == prvc)
					continue;
				dp[i][c] = min(dp[i][c], dp[i-1][prvc] + cost[i][c]);
			}
		}*/
		dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + cost[i][0];
		dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + cost[i][1];
		dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + cost[i][2];		
	}

	cout << min(min(dp[N-1][0], dp[N-1][1]), dp[N-1][2]) << '\n';
}
