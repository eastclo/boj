#include <iostream>
#include <vector>

using namespace std;

int N, del, root;
vector<int> G[50];
int res;

void Post(int n){
	int cnt = 0;
	for(int v : G[n]){
		if(v != del){
			Post(v);
			cnt++;
		}
	}
	if(cnt == 0)
		res++;
}

int main(void){
	cin >> N;
	for(int i = 0; i < N; i++){
		int n;	cin >> n;
		if(n == -1)
			root = i;
		else
			G[n].push_back(i);
	}
	cin >> del;
	if(root == del){
		cout << 0 << '\n';
		return 0;
	}
	Post(root);
	cout << res << '\n';
}
