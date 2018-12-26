#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a, b; cin >> a >> b;

	int A = 3*a, B = 2*b;

	for (int i = 1;1;i++, A*=3, B*=2) {
		if (A > B) {
			cout << i << endl;
			return 0;
		}
	}

	return 0;
}
