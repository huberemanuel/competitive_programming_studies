#include <bits/stdc++.h>

using namespace std;

int main() {

	int n; cin >> n;

	vector< pair<int, int> > v (n);

	for (int i = 0; i < n; ++i) {
		int a, b; cin >> a >> b;
		v[i] = make_pair(a, b);
	}
	
	int total = 0;
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i != j) {
				if (v[i].first == v[j].second) total++;
			}
		}
	}

	cout << total << endl;

	return 0;
}
