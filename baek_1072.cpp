#include <iostream>

#define ll long long

using namespace std;
ll X, Y;

ll f(ll n){
	ll Z = (100*(Y+n)/(X+n));
	return Z;
}

int main(void){
	cin >> X >> Y;
	ll Z = (100*Y/X);
	if(Z>=99){
		cout << -1 << '\n';
		return 0;
	}

	ll lo = 0;
	ll hi = 1e9+1;
	for(int i = 0; i < 40; i++){
		ll mid = (lo+hi)/2;
		if(f(mid) <= Z){
			lo = mid;
		}
		else{
			hi = mid;
		}
	}

	cout << hi << '\n';
}
