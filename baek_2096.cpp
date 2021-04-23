#include <iostream>
#include <algorithm>

using namespace std;


int maxScore[2][4];
int minScore[2][4];

int num[3];

int main(void){
	int N;  cin >> N;
	for(int i = 1; i <= N; i++){
		cin >> num[0] >> num[1] >> num[2];

		maxScore[i%2][1] = max(maxScore[(i-1)%2][1], maxScore[(i-1)%2][2]) + num[0];
		maxScore[i%2][2] = max(max(maxScore[(i-1)%2][1], maxScore[(i-1)%2][2]), maxScore[(i-1)%2][3]) + num[1];
		maxScore[i%2][3] = max(maxScore[(i-1)%2][2], maxScore[(i-1)%2][3]) + num[2];

		minScore[i%2][1] = min(minScore[(i-1)%2][1], minScore[(i-1)%2][2]) + num[0];
		minScore[i%2][2] = min(min(minScore[(i-1)%2][1], minScore[(i-1)%2][2]), minScore[(i-1)%2][3]) + num[1];
		minScore[i%2][3] = min(minScore[(i-1)%2][2], minScore[(i-1)%2][3]) + num[2];
	}
	int max_score = max(max(maxScore[N%2][1], maxScore[N%2][2]), maxScore[N%2][3]);
	int min_score = min(min(minScore[N%2][1], minScore[N%2][2]), minScore[N%2][3]);

	cout << max_score << ' ' << min_score << '\n';
}`
