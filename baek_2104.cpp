#include <iostream>

using namespace std;

int N;
int arr[100101];

long long dnc(int L, int R){
	if(L == R) return (long long)arr[L]*arr[L];
	int mid = (L+R)/2;
	long long ret = max(dnc(L, mid), dnc(mid + 1, R));

	int l = mid, r = mid + 1;
	int h = min(arr[l], arr[r]);
	long long w = arr[l] + arr[r];
	ret = max(ret, h*w);
	while(L < l || r < R){
		if(L == l){
			h = min(h, arr[++r]);
			w += arr[r];
		}
		else if(R == r){
			h = min(h, arr[--l]);
			w += arr[l];
		}
		else if (arr[l-1] < arr[r+1]){
			h = min(h, arr[++r]);
			w += arr[r];
		}
		else{
			h = min(h, arr[--l]);
			w += arr[l];
		}
		ret = max(ret, h*w);
	}
	return ret;
}

int main(void){
	cin >> N;
	for(int i = 1; i <= N; i++)
		cin >> arr[i];

	cout << dnc(1, N) << '\n';
}
