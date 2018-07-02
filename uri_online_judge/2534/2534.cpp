#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, q;

	while (cin >> n >> q)
	{
		vector<int> v (n);

		for (unsigned int i = 0;i < v.size(); ++i) cin >> v[i];

		sort(v.begin(), v.end(), greater<int>());

		while (q--)
		{
			int pos;
			cin >> pos;
			cout << v[pos - 1] << endl;
		}
	}
	
	return 0;
}
