#include <bits/stdc++.h>

using namespace std;

int main() {

	int n;

	while (cin >> n and n) {
		deque<int> Q;
		vector<int> D;

		for (int i = 1;i <= n; ++i) {
			Q.push_back(i);
		}

		while (Q.size() > 1) {
			D.push_back(Q.front());
			Q.pop_front();
			int aux = Q.front();
			Q.pop_front();
			Q.push_back(aux);
		}

		cout << "Discarded cards:";
		for (int i = 0;i < D.size(); ++i) {
			if (i) cout << ",";
			cout << " " <<  D[i];
		}

		cout << endl << "Remaining card: " << Q.front() << endl;

	}

	return 0;
}
