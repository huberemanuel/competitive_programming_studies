#include <bits/stdc++.h>

using namespace std;

int main()
{

	int n, h; cin >> n >> h;

	int res = 0;

	while (n--) {
		int a; cin >> a;
		res += a <= h ? 1 : 2;
	}

	cout << res << endl;

	return 0;
}
