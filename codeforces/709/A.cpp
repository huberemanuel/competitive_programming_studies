#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, b, d; cin >> n >> b >> d;
	vector<int> v;

	for (int i = 0; i < n; ++i) {
		int aux; cin >> aux;
		if (aux <= b)
			v.push_back(aux);
	}

	int cleaned = 0, ac = 0;

	for (int i = 0; i < v.size(); ++i) {
		ac += v[i];
		if (ac > d) {
			ac = 0;
			cleaned++;
		}
	}

	cout << cleaned << endl;

	return 0;
}
