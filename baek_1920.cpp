#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
	int N; cin >> N;
	int set[100000];
	for(int i = 0; i < N; i++)
		cin >> set[i];

	sort(set, set + N);

	int M; cin >> M;
	int arr[100000];
	for(int i = 0; i < M; i++)
		cin >> arr[i];

	for(int i = 0; i < M; i++){
		cout << binary_search(set, set+N, arr[i]) << '\n';
	}
}

