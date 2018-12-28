#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n; cin >> n;
	int last = -1, total = 1;
	while (n--) {
		int actual; cin >> actual;
		if (last == -1) last = actual;
		else {
			if (last != actual) total++;
			last = actual;
		}
	}

	cout << total << endl;

	return 0;
}
