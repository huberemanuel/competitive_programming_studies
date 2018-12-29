#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	cin >> s;

	int one, two, three;
	one = two = three = 0;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '1') one++;
		else if (s[i] == '2') two++;
		else if (s[i] == '3') three++;
	}

	bool newAdd = false;

	while (one--) {
		if (newAdd) cout << "+";
		newAdd= true;
		cout << 1;
	}
	while (two--) {
		if (newAdd) cout << "+";
		newAdd= true;
		cout << 2;
	}
	while (three--) {
		if (newAdd) cout << "+";
		newAdd= true;
		cout << 3;
	}
	cout << endl;

	return 0;
}
