#include <bits/stdc++.h>

using namespace std;
const int MN = 12;
const int INF = 1e9;

int mmin = INF, mmax = -INF, N;
int num[MN];
vector<int> oper;
int cal()
{
	int ret = num[0];
	for(int i = 0; i < N-1; i++) {
		if(oper[i] == 0)
			ret += num[i+1];
		else if(oper[i] == 1)
			ret -= num[i+1];
		else if(oper[i] == 2)
			ret *= num[i+1];
		else	
			ret /= num[i+1];
	}
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N;
	for(int i = 0; i < N; i++) 
		cin >> num[i];

	for(int i = 0; i < 4; i++) {
		int cnt;	cin >> cnt;
		for(int j = 0; j < cnt; j++) 
			oper.push_back(i);
	}

	do {
		int res = cal();
		mmin = min(mmin, res);
		mmax = max(mmax, res);
		
	}while(next_permutation(oper.begin(), oper.end()));
	cout << mmax << '\n' << mmin;
}
