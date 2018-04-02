#include <bits/stdc++.h>

using namespace std;

int main()
{
	map<string, int> trees;
	int trees_count, cases;
	bool blank_line = false;
	string s;
	
	cout << fixed;
	cout << setprecision(4);

	cin >> cases;
	getline(cin, s);
	getline(cin, s);

	while (cases--)
	{
		trees_count = 0;
		trees.clear();

		if (blank_line) cout << endl;

		while (getline(cin, s) and not s.empty())
		{
			trees[s]++;
			trees_count++;
		}

		for (auto it = trees.begin(); it != trees.end(); ++it)
		{
			cout << it->first << " " << (it->second * 100.0) / trees_count << endl;
		}

		blank_line = true;
	}

	return 0;
}
