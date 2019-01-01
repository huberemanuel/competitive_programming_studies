#include <bits/stdc++.h>

using namespace std;

int main()
{
	string n1, n2;

	while (cin >> n1 >> n2) {
		vector<int> v (550, 0);
		reverse(n1.begin(), n1.end());
		reverse(n2.begin(), n2.end());
		
		for (int i = 0; i < n2.size(); ++i) {
			for (int j = 0; j < n1.size(); ++j) {
				v[v.size() - 1 - j - i] += (n1[j]-'0') * (n2[i]-'0');
			}
		}

		for (int i = v.size() - 1; i > 0; --i) {
			v[i - 1] += v[i] / 10;
			v[i] = v[i] % 10;
		}

		while  (v[0] == 0 and v.size() > 1) 
			v.erase(v.begin());

		for (int i = 0; i < v.size(); ++i) 
			cout << v[i];

		cout << endl;
	}

	return 0;
}
