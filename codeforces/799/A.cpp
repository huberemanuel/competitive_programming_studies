#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, t, k, d; cin >> n >> t >> k >> d;
	int bakes = 0, oven1 = 0, oven2 = 0;
	int time = 1;
	while (oven1 < n && (oven1 + oven2) < n) {
		if (time > d) {
			if ((time - d) % t == 0)
				oven2 += k;
		}
		if (time % t == 0)
			oven1 += k;

		time++;
	}

	if (oven1 < n)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}
