#include <bits/stdc++.h>

using namespace std;
const int MN = 1;
const int INF = 1e9;

int main(void)
{
	int res;
	scanf("%d ", &res);
	char a;
	int b;
	bool check = false;
	while(scanf("%c %d ", &a, &b) != EOF) {
		if(check) 
			res -= b;
		else {
			if(a == '+') 
				res += b;
			else {
				check = true;
				res -= b;
			}
		}
	}
	printf("%d", res);
}
