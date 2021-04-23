#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[300];
vector<int> res;

int f(int sum){
	int ret = 1;
	int tmp = 0;
	for(int i = 0; i < N; i++){
		if(arr[i] > sum)
			return 30000;

		if(tmp + arr[i] > sum){
			tmp = arr[i];
			ret++;
		}
		else
			tmp += arr[i];
	}

	return ret;
}

int main(void){
	cin >> N >> M;
	for(int i = 0; i < N; i++)
		cin >> arr[i];

	int lo = 0, hi = 30000;
	for(int i = 0; i < 20; i++){
		int mid = (lo + hi) / 2;
		if(f(mid) > M)
			lo = mid;
		else
			hi = mid;
	}

	cout << hi << '\n';

	int sum = arr[0];
	int cnt = 1;
	for(int i = 1; i < N; i++){
		if(sum + arr[i] > hi){
			res.push_back(cnt);
			sum = arr[i];
			cnt = 1;
		}
		else{
			cnt++;
			sum += arr[i];
		}
	}
	res.push_back(cnt);

	if(res.size() == M)
		for(int out : res)
			cout << out << ' ';
	else{
		int T = M - res.size();
		for(int out : res){
			if(out != 1 && T){
				while(out != 1){
					cout << 1 << ' ';
					out--;
					T--;
					if(T == 0)
						break;
				}
			}
			cout << out << ' ';
		}
	}
}
