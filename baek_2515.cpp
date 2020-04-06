#include <bits/stdc++.h>
using namespace std;
#define P pair<int, int>
int N, S, i, dp[300101];
P pic[300101];
int main()
{
	scanf("%d %d", &N, &S);
	for(i = 1; i <= N; i++)
		scanf("%d %d", &pic[i].first, &pic[i].second);

	sort(pic + 1, pic + N + 1);
	for(i = 1; i <= N; i++){
		int idx = upper_bound(pic + 1, pic + i + 1, P(pic[i].first - S, 1000)) - pic;
		dp[i] = max(dp[idx-1] + pic[i].second, dp[i-1]);
	}
	printf("%d\n",dp[N]);
}
