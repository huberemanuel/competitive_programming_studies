#include <bits/stdc++.h>

using namespace std;

int main() {

	int k, r;
	cin >> k >> r;

	for (int i = 1; ; ++i) {
		int a = (k*i) % 10;
		if (a == 0 or a == r) {
			cout << i << endl;
			break;
		}
	}

	return 0;
}
