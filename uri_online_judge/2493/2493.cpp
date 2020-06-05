#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    
	
	while (cin >> T) {

		vector< pair< int, pair<int, int> > > E;

		for (int i = 0; i < T; ++i) {
			int a, b, c;
			scanf("%d %d=%d", &a, &b, &c);
			E.push_back( make_pair(a, make_pair(b, c)) );
		}

		set<string> losers;

		for (int i = 0; i < T; ++i) {

			string name;
			int ind;
			char op;

			cin >> name >> ind >> op;

			if (op == '+' && E[ind-1].first + E[ind-1].second.first != E[ind-1].second.second) {
				losers.insert(name);
			}
			else if (op == '-' && E[ind-1].first - E[ind-1].second.first != E[ind-1].second.second) {
				losers.insert(name);
			}
			else if (op == '*' && E[ind-1].first * E[ind-1].second.first != E[ind-1].second.second) {
				losers.insert(name);
			}
			else if (op == 'I' && (
					(E[ind-1].first + E[ind-1].second.first == E[ind-1].second.second) ||
					(E[ind-1].first - E[ind-1].second.first == E[ind-1].second.second) ||
					(E[ind-1].first * E[ind-1].second.first == E[ind-1].second.second))) {
				losers.insert(name);
			}
		}

		if (losers.size() == T) {
			cout << "None Shall Pass!" << endl;
		}
		else if (losers.size() == 0) {
			cout << "You Shall All Pass!" << endl;
		}
		else {
			for (auto it = losers.begin(); it != losers.end(); ++it) {
				if (it != losers.begin())
					cout << " ";
				cout << *it;
			}
			cout << endl;
		}

	}
    
	return 0;
}
