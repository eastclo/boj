#include <bits/stdc++.h>

using namespace std;

const int MN = 101;

int dp[MN][MN];
int h[MN][MN]; 
bool is_same_cnt[MN][MN]; 
int P[MN][MN];
int arr[MN];
pair<int, int> cnt[MN];
vector<pair<int,int>> res2;
int res;

void check_same(int n)
{
	for(int i = 1; i <= n - 1; i++) {
		for(int j = i + 1; j <= n; j++) {
			int white = cnt[j].first - cnt[i-1].first;
			int black = cnt[j].second - cnt[i-1].second;
			if(white == black) 
				is_same_cnt[i][j] = true;
		}
	}
}

void make_conn(int i, int j)
{
	if(P[i][j] == j) {
		res2.push_back({i,j});
		if(i+1 < j-1)
			make_conn(i+1, j-1);
	}
	else {
		make_conn(i, P[i][j]);
		make_conn(P[i][j] + 1, j);
	}
}

int main(void)
{
	int N;
	scanf("%d", &N);

	int white = 0, black = 0;
	for(int i = 1; i <= N; i++) {
		scanf("%1d", &arr[i]);	
		if (arr[i] == 0) white++;
		else black++;

		cnt[i].first = white;
		cnt[i].second = black;
	}

	check_same(N);

	for(int i = 1; i < N; i++)
		for(int j = i + 1; j <= N; j++)
			dp[i][j] = 1e9;

	for(int diagonal = 1; diagonal <= N-1; diagonal += 2) {
		for(int i = 1; i <= N-diagonal; i++) {
			int j = i + diagonal;
			if(!is_same_cnt[i][j])
				continue;

			if(arr[i] != arr[j]) {
				h[i][j] = h[i+1][j-1] + 1;
				dp[i][j] = dp[i+1][j-1] + h[i][j] * 2 + (j-i);
				P[i][j] = j;
			}

			for(int k = i + 1; k < j; k+=2){
				if(!is_same_cnt[i][k])
					continue;

				if(dp[i][j] > dp[i][k] + dp[k+1][j]) {
					dp[i][j] = dp[i][k] + dp[k+1][j];
					h[i][j] = max(h[i][k], h[k+1][j]);
					P[i][j] = k;
				}
			}
		}
	}

	make_conn(1, N);
	sort(res2.begin(), res2.end());
	printf("%d\n", dp[1][N]);

	for(pair<int, int> ans : res2)
		printf("%d %d\n", ans.first, ans.second);
}
