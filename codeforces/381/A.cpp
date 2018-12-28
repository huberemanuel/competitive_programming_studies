#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n; cin >> n;
	vector<int> v (n);
	for (int i = 0;i < n; ++i) cin >> v[i];
	int sereja = 0, dima = 0, turn = 0;

	while (!v.empty()) {
		int maxe;
		if (v.front() > v.back()) {
			maxe = v.front(); v.erase(v.begin());
		}
		else {
			maxe = v.back(); v.erase(v.begin() + v.size() - 1);
		}
		if (turn++ % 2 == 0)
			sereja += maxe;
		else
			dima += maxe;
	}

	cout << sereja << " " << dima << endl;

	return 0;
}
