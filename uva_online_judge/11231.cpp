#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, m ,c;

	while (cin >> n >> m >> c and (n+m+c) > 0) {
		int total = 0;
		for (int i = 0; i <= n - 8; ++i) {
			if ((i + c) % 2 == 0) total += (m - 1) / 2 - 3;
			else total += m / 2 - 3;
		}
		cout << total << endl;
	}

	return 0;
}
