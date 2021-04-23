#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int a, b, v;	cin >> a >> b >> v;

	int tmp = (v-a) / (a-b);
	int tmp2 = (v-a) % (a-b);

	if(tmp2 == 0)
		cout << tmp + 1;
	else
		cout << tmp + 2;
}
