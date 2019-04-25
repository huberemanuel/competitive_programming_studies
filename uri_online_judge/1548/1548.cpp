#include <bits/stdc++.h>

using namespace std;

int main() {

	int n; cin >> n;

	while (n--) {
		int a; cin >> a;
		vector<int> v (a);
		for (int i = 0; i < a; ++i) {int aux; cin >> aux; v[i] = aux;}
		vector<int> v1;
		v1.insert(v1.begin(), v.begin(), v.end());
		sort(v1.begin(), v1.end(), greater<int>());
		int not_changed = 0;
		for (int i = 0; i < a; ++i) {
			if (v[i] == v1[i]) not_changed++;
		}
		cout << not_changed << endl;
	}


	return 0;
}
