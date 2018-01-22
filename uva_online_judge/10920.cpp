#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	ll sz, p, x, y;
	
	while (cin >> sz >> p, sz || p)
	{
		ll i = 1;
		while (p > i*i) i += 2;
		
		if (i == 1) {
			cout << "Line = " << 1 + sz / 2 << ", column = " << 1 + sz / 2 << "." << endl;
			continue;
		}
		
		
		ll lb = (i - 2) * (i - 2), pad = (sz - i) /2;

		if(p <= lb + i-1) 
		{
			// NORTH side        
			x = lb + i - p + pad;
			y = sz - pad;
		} 
		 
		else if (lb + i - 1 < p && p <= lb + 2 * (i - 1)) 
		{
			// WEST side
			x = pad + 1;
			y = lb + (i - 1) * 2 + 1 - p + pad;
		} 
		
		else if(lb + 2 * (i - 1) < p && p <= lb + 3 * (i - 1)) 
		{
			// SOUTH side
			x = p - (lb + 2 * (i - 1)) + pad + 1;
			y = pad + 1;
		} 
		
		else 
		{
			// EAST side
			x = sz - pad;
			y = p - (lb + 3 * (i - 1)) + pad + 1;
		}
		
		cout << "Line = " << y << ", column = " << x << "." << endl;
	}
	
	return 0;
}
