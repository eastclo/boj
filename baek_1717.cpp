#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1e6;

int par[MAX_N+1], rnk[MAX_N+1];

void init(int N){
	for(int i = 1; i <= N; i++)
		par[i] = i, rnk[i] = 1;
}

int find(int x){
	if(par[x] == x)
		return x;
	else
		return par[x] = find(par[x]);
}

void unite(int x, int y){
	x = find(x), y = find(y);
	if( x == y )
		return;
	if(rnk[x] > rnk[y]){
		swap(x, y);
	}
	par[x] = y;
	if(rnk[x] == rnk[y])
		rnk[y]++;
}

vector<int> ans;
int main(void){
	int N, M;       cin >> N >> M;

	init(N);
	for(int i = 0; i < M; i++){
		int opr, a, b;  cin >> opr >> a >> b;
		if(opr == 0)
			unite(a, b);
		else if (find(a) == find(b))
			ans.push_back(1);
		else
			ans.push_back(0);
	}

	for(int i = 0; i < ans.size(); i++){
		if(ans[i] == 1)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
}
