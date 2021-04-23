#include <iostream>
#include <algorithm>

using namespace std;

const int MN = 100101;
const int INF = 2123456789;

int arr[MN];
int main(void){
	int N, M;       cin >> N >> M;
	for(int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr, arr + N);
	int res = INF;
	for(int i = 0; i < N; i++){
		int idx = lower_bound(arr, arr + N, arr[i] + M) - arr;
		int def = arr[idx] - arr[i];
		if(res > def && idx < N){
			res = def;
		}
	}
	cout << res << '\n';
}
