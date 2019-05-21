#include <bits/stdc++.h>

using namespace std;

int main() {

	int n; cin >> n;
	int cops = 0,  untreated = 0;

	for (int i = 0; i < n; ++i) {
		int a; cin >> a;
		if (a > 0) cops += a;
		else if (cops == 0) untreated++;
		else cops--;
	}

	cout << untreated << endl;

	return 0;
}
