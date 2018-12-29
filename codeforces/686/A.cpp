#include <bits/stdc++.h>

#define ll long long 

using namespace std;

int main()
{
	ll n, x; cin >> n >> x;
	ll sad = 0;

	while (n--) {
		char c; ll a;
		scanf(" %c", &c);
		cin >> a;
		if (c == '+')
			x += a;
		else if (x >= a) 
			x -= a;
		else
			sad++;
	}

	cout << x << " " << sad << endl;

	return 0;
}
