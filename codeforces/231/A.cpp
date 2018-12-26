#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n; cin >> n;
	int res = 0;
	while (n--) {
		int a, b, c;
		cin >> a >> b >> c;
		res += a + b + c >= 2 ? 1 : 0;
	}

	cout << res << endl;

	return 0;
}
