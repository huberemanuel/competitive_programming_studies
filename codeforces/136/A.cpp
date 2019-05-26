#include <bits/stdc++.h>

using namespace std;

int main() {

	int n; cin >> n;
	vector<int> v(n);

	for (int i = 0;i < n; ++i) {
		int a; cin >> a;
		v[a-1] = i + 1;
	}

	for (int i = 0;i < n; ++i) {
		if (i != 0) cout << " ";
		cout << v[i];
	}
	cout << endl;

	return 0;
}
