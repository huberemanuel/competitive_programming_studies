// Esse deu trabalho, use sua imaginação para casos de teste, mas no fundo é só uma dfs.

#include <bits/stdc++.h>

using namespace std;

#define si set<int>

map<int, si> desejos;
set<int> visiteds;
int k;

pair<int, bool> dfs(int from) {
	int last = -1;
	visiteds.clear();
	stack< pair<int, int> > S;

	S.push(make_pair(from, -1));

	while (!S.empty()) {
		int actual = S.top().first;

		int previous = S.top().second;
		S.pop();

		if (visiteds.find(actual) != visiteds.end() and visiteds.size() != k) return make_pair(-1, false);
		else if (visiteds.find(actual) != visiteds.end()) return make_pair(visiteds.size(), true);

		visiteds.insert(actual);
		int diff = 0;
		for (int neigh : desejos[actual]) {
			if (neigh != previous) {
				S.push(make_pair(neigh, actual));
				diff++;
			}
		}
		if ((previous != -1 and diff > 1) || diff > 2) return make_pair(-1, false);
	}

	return make_pair(visiteds.size(), false);
}

int main() {

	int  w;

	while (true) {
		cin >> k >> w; if (k == 0 and w == 0) return 0;

		desejos.clear();

		for (int i = 0; i < w; ++i) {
			int from, to; cin >> from >> to;
			desejos[from].insert(to);
			desejos[to].insert(from);
		}

		bool cheguei = false;

		for (map<int, si>::iterator it = desejos.begin(); it != desejos.end(); ++it) {
			auto result = dfs(it->first);
			// printf("Resposta: %d %d\n", result.first, result.second);
			if (result.first == -1 || (result.first != k and result.second)) {
				cheguei = true; 
				cout << "N\n"; break;
			}
			else if (result.first == k) break;

		}

		if (not cheguei) {
			cout << "Y\n";
		}
	}

	return 0;
}
