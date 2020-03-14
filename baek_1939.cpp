#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MN = 1e4;
const int MM = 1e5;

struct edge{
	int nxt, w;
	int idx;
	edge(int nxt, int w, int idx) : nxt(nxt), w(w), idx(idx) {}
};

int N, M;
int U, V;
vector<edge> G[MN+1];

bool f(int w){
	queue<int> q;
	q.push(U);

	bool visited[MM];
	for(int i = 0; i < M; i++){
		visited[i] = false;
	}

	while(!q.empty()){
		int cur = q.front(); q.pop();

		for(edge nxt_edge : G[cur]){
			int nxt_w = nxt_edge.w;
			int nxt = nxt_edge.nxt;
			int idx = nxt_edge.idx;
			if(!visited[idx] && nxt_w >= w){
				if(nxt == V)
					return true;
				q.push(nxt);
				visited[idx] = true;
			}
		}
	}
	return false;
}

int main(void){
	cin >> N >> M;
	for(int i = 0; i < M; i++){
		int u, v, w;    cin >> u >> v >> w;
		G[u].push_back(edge{v, w, i});
		G[v].push_back(edge{u, w, i});
	}
	cin >> U >> V;

	int lo = 0, hi = 1e9+1;
	for(int i = 0; i < 40; i++){
		int mid = (lo+hi)/2;
		if(f(mid)) lo = mid;    //mid 중량일 때 지나다닐 수 있으면 true
		else hi = mid;  //없으면 false
	}

	cout << lo << '\n';
}
