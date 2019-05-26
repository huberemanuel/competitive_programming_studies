#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>

int main() {

	int n; cin >> n;
	pii p[n];

	for (int i = 0; i < n; ++i) {
		cin >> p[i].first;
		p[i].second = i;
	}

	sort(p, p + n);

	int mi[n], ma[n];

	for (int i = 0; i < n; ++i) {
		if (i == 0) {
			mi[p[i].second] = abs(p[i].first - p[i+1].first);
			ma[p[i].second] = abs(p[i].first - p[n-1].first);
		}
		else if (i == (n - 1)) {
			mi[p[i].second] = abs(p[i].first - p[i-1].first);
			ma[p[i].second] = abs(p[i].first - p[0].first);
		}
		else {
			mi[p[i].second] = min( abs(p[i].first - p[i-1].first), abs(p[i].first - p[i+1].first) );
			ma[p[i].second] = max( abs(p[i].first - p[0].first), abs(p[i].first - p[n-1].first) );
		}
	}

	for (int i = 0; i < n; ++i) {
		cout << mi[i] << " " << ma[i] << endl;
	}

	return 0;
}
