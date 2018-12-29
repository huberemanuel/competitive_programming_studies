#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n; cin >> n;
	set<int> one, two, three;

	for (int i = 0;i < n; ++i) {
		int a; cin >> a;
		if (a == 1) one.insert(i+1);
		else if (a == 2) two.insert(i+1);
		else if (a == 3) three.insert(i+1);
	}

	int min_team = min(min(one.size(), two.size()), three.size());
	cout << min_team << endl;

	for (int i = 0;i < min_team; ++i) {
		cout << *one.begin() << " " << *two.begin() << " " << *three.begin() << endl;
		one.erase(one.begin());
		two.erase(two.begin());
		three.erase(three.begin());
	}

	return 0;
}
