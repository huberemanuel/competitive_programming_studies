/*
	Resources for understanding the solution:
	https://www.youtube.com/watch?v=Ska6aftCl-k
	https://math.stackexchange.com/questions/525935/why-perfect-square-has-odd-number-of-factors
*/


#include <bits/stdc++.h>

using namespace std;

int main()
{
	unsigned int n;
	while (cin >> n and n != 0) {
		int sqr = sqrt(n);
		if (sqr*sqr == n) cout << "yes" << endl;
		else cout << "no" << endl;
	}
	return 0;
}
