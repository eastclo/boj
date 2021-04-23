#include <bits/stdc++.h>

using namespace std;
#define ll long long

struct P {ll X, Y;};
P arr[10101];
double adbc(P A, P B) { return A.X*B.Y - B.X*A.Y; }

int main()
{
	int N;	cin >> N;
	for(int i = 0; i < N; i++) 
		scanf("%lld %lld", &arr[i].X, &arr[i].Y);

	double res = 0;
	for(int i = 0; i < N-1; i++) 
		res += adbc(arr[i], arr[i+1]);
	res += adbc(arr[N-1], arr[0]);

	printf("%.1lf", abs(res/2));
}
