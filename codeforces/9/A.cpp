#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	a = max(a, b);

	map<int, string> res = {
		{6, "1/6"},
		{5, "1/3"},
		{4, "1/2"},
		{3, "2/3"},
		{2, "5/6"},
		{1, "1/1"}
	};

	cout << res[a] << endl;

	return 0;
}
