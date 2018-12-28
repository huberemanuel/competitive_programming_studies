#include <bits/stdc++.h>

using namespace std;

int  main()
{
	int n; cin >> n;
	vector<int> rows(n);
	for (int i = 0; i < n; ++i) cin >> rows[i];
	int shots; cin >> shots;
	while(shots--) {
		int row, bird; cin >> row >> bird;
		int left = bird - 1;
		int right = rows[row - 1] - bird;
		if (row > 1) {
			rows[row - 2] += left;
		}
		else {
			rows[row - 1] -= left;
		}
		if (row < n) {
			rows[row] += right;
		}
		else {
			rows[row - 1] -= right;
		}
		rows[row - 1] = 0;
	}

	for (auto it = rows.begin(); it != rows.end(); it++)
		cout << *it << endl;

	return 0;
}
