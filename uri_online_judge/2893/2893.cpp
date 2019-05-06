#include <bits/stdc++.h>

#define MOD 1000007

using namespace std;

int main() {

	int cases; cin >> cases;

	while (cases--) {
		vector<unsigned long long> v;
		int k, n; cin >> k >> n;
		if (n <= k) {
			cout << (n - 1) % MOD << endl;
		}
		else {
			for (int i = 0; i < k; ++i) v.push_back(i);
			for (int i = k; i < n; ++i) {
				unsigned long long value = 0;
				for (int j = 0; j < k; ++j) value += v[i-k+j];
				v.push_back(value % MOD);
			}
			
			cout << v[n - 1] << endl;
		}
	}

	return 0;
}
