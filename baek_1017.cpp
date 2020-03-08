#include <bits/stdc++.h>

using namespace std;
const int MN = 2010;
const int INF = 2e9;

vector<int> G[MN];
vector<int> res;
int c[MN][MN], f[MN][MN];       // c[a][b] = a 에서 b로 가는 간선의 용량
int arr[MN];
bool sieve[MN];
int MaxFlow(int src, int snk){
	int ret = 0;
	while(1){
		queue<int> q;   q.push(src);
		vector<int> p(MN, -1); p[src] = src;   //최단경로에서 직전에 건너온 경로
		while(!q.empty()){      // 방문하지 않으면 -1
			int n = q.front();      q.pop();
			for(int next : G[n]){
				if(c[n][next] - f[n][next] > 0 && p[next] == -1){
					q.push(next);
					p[next] = n;
				}
			}
		}
		if(p[snk] == -1) break;
		int flow = INF;
		for(int i = snk; i !=src; i=p[i])
			flow = min(flow, c[p[i]][i] - f[p[i]][i]);
		for(int i = snk; i !=src; i=p[i]){
			f[p[i]][i] += flow;
			f[i][p[i]] -= flow;     //유량의 대칭성
		}
		ret += flow;
	}
	return ret;
}

void initC(int i, int j, int num){
	j += 1000;
	c[0][i] = num;
	c[i][j] = num;
	c[j][2001] = num;
}

void initF(){
	for(int i = 0; i < MN; i++)
		for(int j = 0; j < MN; j++)
			f[i][j] = 0;
}

int main(void){
	for(int p = 2; p * p < MN; p++){
		if(sieve[p])
			continue;
		for(int i = p * p; i < MN; i += p)
			sieve[i] = true;
	}

	int N;	cin >> N;
	for(int i = 1; i <= N; i++)
		cin >> arr[i];

	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			if(i == j) continue;

			int check = arr[i] + arr[j];
			if(sieve[check] == false){
				int a = arr[i], b = arr[j] + 1000;
				G[a].push_back(b);
				G[b].push_back(a);	
				G[0].push_back(a);
				G[a].push_back(0);
				G[b].push_back(2001);
				G[2001].push_back(b);

				c[0][a] = 1;
				c[a][b] = 1;
				c[b][2001] = 1;
			}
		}
	}
	if(MaxFlow(0, 2001) != N){
		cout << -1 << '\n';
		return 0;
	}
	
	int a = arr[1], b;
	for(int node : G[a]){
		if(node == 0 || node == 2001) continue;
		b = node - 1000;
		initF();
		initC(a, b, 0);
		int ret = MaxFlow(0, 2001);
		if(ret + 1 == N)
			res.push_back(b);		

		initC(a, b, 1);
	}
	sort(res.begin(), res.end());
	for(int out : res)
		cout << out << ' ';
	cout << '\n';
}
