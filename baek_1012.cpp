#include <iostream>
#include <vector>

using namespace std;

int di[] = { 1, -1, 0, 0 };
int dj[] = { 0, 0, -1, 1 };

int N, M;
bool visited[50][50];
bool map[50][50];

void dfs(int ci, int cj){
	visited[ci][cj] = true;

	for(int d = 0; d < 4; d++){
		int ni = ci + di[d];
		int nj = cj + dj[d];

		if( 0 <= ni && ni < M && 0 <= nj && nj < N)
			if(!visited[ni][nj] && map[ni][nj])
				dfs(ni, nj);
	}
}

int main(void){
	vector<int> res;
	int T;	cin >> T;
	for(int n = 0; n < T; n++){
		int K; cin >> N >> M >> K;

		for(int i = 0; i < 50; i++){
			for(int j = 0; j < 50; j++)
				visited[i][j] = false;
		}
		
		for(int i = 0; i < 50; i++){
			for(int j = 0; j < 50; j++)
				map[i][j] = false;
		}
		
		for(int k = 0; k < K; k++){
			int a, b; cin >> a >> b;
			map[b][a] = true;
		}
		
		
		int cnt = 0;
		for(int i = 0; i < M; i++){
			for(int j = 0; j < N; j++)
				if(!visited[i][j] && map[i][j]){
					dfs(i, j);
					cnt++;
				}
		}
		
		res.push_back(cnt);
	}

	for(int i = 0; i < res.size(); i++)
		cout << res[i] << '\n';
}
