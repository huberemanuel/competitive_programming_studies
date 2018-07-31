#include <bits/stdc++.h>

using namespace std;

int main() {

	int n, m;

	while (cin >> n >> m, n and m)
	{
		vector<int> v (3); cin >> v[0] >> v[1] >> v[2]; sort(v.begin(), v.end());
		vector< pair<int, pair<int, int>> > boxes;
		int total = 1e6;
		bool impossible = true;

		for (int i = 0;i < m; ++i) {
			vector<int> aux(3); cin >> aux[0] >> aux[1] >> aux[2]; sort(aux.begin(), aux.end());
			boxes.push_back(make_pair(aux[0], make_pair(aux[1], aux[2])));
		}
		//for (auto box : boxes)
		//	cout << "Box: " << box.first << " " << box.second.first << " " << box.second.second << endl; 

		//	cout << endl;

		sort(boxes.begin(), boxes.end());

		for (auto box : boxes) {
			//cout << "Box: " << box.first << " " << box.second.first << " " << box.second.second << endl; 
			if (v[0] <= box.first and v[1] <= box.second.first and v[2] <= box.second.second) {
				n--;
				total = min(total, box.first*box.second.first*box.second.second-v[0]*v[1]*v[2]);
			if (n == 0) break;
			}
		}

		if (n) cout << "impossible" << endl;
		else cout << total << endl;
	}

	return 0;
}
