#include <iostream>

using namespace std;

const long long MAX_N = 1e7;
bool sieve[MAX_N+1];

int main(void){
	for(int p = 2; p * p <= MAX_N; p++){
		if(sieve[p])
			continue;
		for(int i = p * p; i <= MAX_N; i += p)
			sieve[i] = true;
	}

	long long a, b;	cin >> a >> b;

	long long result = 0;
	for(long long i = 2; i <= MAX_N; i++){
		if(sieve[i] == false){
			long long tmp = i;
			while(true){
				if(tmp > b/i)
					break;
				tmp *= i;
				if(tmp < a)
					continue;

				result++;
			}
		}
	}

	cout << result << '\n';
}
