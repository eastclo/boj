#include <bits/stdc++.h>

using namespace std;

const int MN = 17;
const int INF = 1e9;

int dp[MN][(1<<MN)];
int w[MN][MN];
int N;
int tsp(int n, int curset){
	int &ret = dp[n][curset];
	if(curset == (1<<N)-1) 
		return w[n][1] ? w[n][1] : INF;
	if(ret > 0) return ret;

	ret = INF;
	for(int i = 0; i < N; i++) {
		if(!w[n][i+1]) continue;
		if(!(curset & (1 << i))) 
			ret = min(ret, tsp(i+1, curset | (1<<i)) + w[n][i+1]);
	}
	return ret;
}

int main(void) {
	cin >> N;
	for(int i = 1; i <= N; i++) 
		for(int j = 1; j <= N; j++) 
			cin >> w[i][j];

	cout << tsp(1, 1);
}
