#include <bits/stdc++.h>

using namespace std;
const int MN = 51;
const int INF = 1e9;

int arr[MN][MN];
int main(void)
{
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N, M;	cin >> N >> M;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			char a;	cin >> a;
			if(a == 'W')
				arr[i][j] = 1;
			else
				arr[i][j] = -1;
		}
	}

	int res = INF;
	for(int i = 0; i < N-7; i++) {
		for(int j = 0; j < M-7; j++) {
			int cnt = 0;
			int check = 1;
			for(int x = i; x < i+8; x++) {
				for(int y = j; y < j+8; y++) {
					if(arr[x][y] != check)
						cnt++;
					check = -1 * check;
				}
				check = -1 * check;
			}
			res = min(res, cnt);

			check = -1;
			cnt = 0;
			for(int x = i; x < i+8; x++) {
				for(int y = j; y < j+8; y++) {
					if(arr[x][y] != check)
						cnt++;
					check = -1 * check;
				}
				check = -1 * check;
			}
			res = min(res, cnt);
		}
	}
	cout << res;
}
