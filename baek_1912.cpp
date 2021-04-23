#include <iostream>	//dnc

using namespace std;

struct Node{
	int sum, lm, rm, tm;
};

const int INF = 2e9;

int A[100101];

Node dnc(int L, int R){
	Node ret;
	if(L==R){
		ret.sum = ret.lm = ret.rm = ret.tm = A[L];
		return ret;
	}
	int mid = (L+R)/2;
	Node Lnode = dnc(L, mid);
	Node Rnode = dnc(mid + 1, R);

	ret.sum = Lnode.sum + Rnode.sum;
	ret.lm = max(Lnode.lm, Lnode.sum + Rnode.lm);
	ret.rm = max(Rnode.rm, Rnode.sum + Lnode.rm);
	ret.tm = max(max(Lnode.tm, Rnode.tm), Lnode.rm + Rnode.lm);

	return ret;
}

int main(void){
	int N;  cin >> N;
	for(int i = 1; i <= N; i++)
		cin >> A[i];

	cout << dnc(1, N).tm << '\n';
}
/*	dp
#include <iostream>

using namespace std;

const int INF = 1e9;

int arr[100101];
int dp[100101];
int main(void){
        int N;  cin >> N;
        for(int i = 0; i < N; i++)
                cin >> arr[i];

        int res = -INF;
        dp[0] = arr[0];
        res = max(res, dp[0]);
        for(int i = 1; i < N; i++){
                dp[i] = max(dp[i-1], 0) + arr[i];
                res = max(res, dp[i]);
        }

        cout << res << '\n';
} 
*/