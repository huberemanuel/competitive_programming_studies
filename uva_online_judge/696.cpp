#include <bits/stdc++.h>

using namespace std;

int solve(int n, int m){
    if(n > m) swap(n,m);
    if(n == 1) return m;
    if(n == 2) return m / 4 * 4 + (m % 4 == 1 ? 2 : (m % 4 >= 2 ? 4 : 0));
    return (n*m + 1) / 2;
}

int main()
{
	int m, n;
	
	while (cin >> m >> n and !(m == 0 and n == 0))
		cout << solve(m, n) << " knights may be placed on a " << m << " row " << n << " column board." << endl;

	return 0;
}

