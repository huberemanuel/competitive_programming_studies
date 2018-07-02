#include <bits/stdc++.h>

using namespace std;

struct Competitor
{
	string name;
	int gold, silver, bronze;
};

int main()
{
	int n;

	cin >> n;
	cin.ignore();

	vector<Competitor> v;

	while (n--)
	{
		string a; int b, c, d;
		cin >> a >> b >> c >> d;
		cin.ignore();

		Competitor C = {a, b, c, d};
		v.push_back(C);

	}

	auto comp = [](const Competitor a, const Competitor b){ 
		return (a.gold > b.gold ||
			a.gold == b.gold and a.silver > b.silver ||
			a.gold == b.gold and a.silver == b.silver and a.bronze > b.bronze ||
			a.gold == b.gold and a.silver == b.silver and a.bronze == b.bronze and a.name < b.name);
	};

	sort (v.begin(), v.end(), comp);

	for (auto c : v)
		printf("%s %d %d %d\n", c.name.c_str(), c.gold, c.silver, c.bronze);

	return 0;
}
