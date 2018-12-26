#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n; cin >> n;
	vector<int> piles (n);
	for (int i = 0;i < n; ++i) cin >> piles[i];

	bool state = true;
	while (state) {
		state = false;
		for (int i = n-2; i >= 0; --i) {
			if (piles[i] > piles[i + 1]) {
				int diff = piles[i] - piles[i + 1];
				piles[i] -= diff;
				piles[i + 1] += diff;
				state = true;
			}
		}
	}

	for (int i = 0;i < n; ++i) {
		if (i > 0) cout << " ";
		cout << piles[i];
	}
	cout << endl;

	return 0;
}
