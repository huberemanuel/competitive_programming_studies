#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n; cin >> n; cin.ignore();
	string s; getline(cin, s);
	int remove = 0, i = 1;
	while (!s.empty() and i < s.size()) {
		if (s[i] == s[i-1]) {
			remove++;
			s.erase(s.begin() + i);
		}
		else
			i++;
	}

	cout << remove << endl;

	return 0;
}
