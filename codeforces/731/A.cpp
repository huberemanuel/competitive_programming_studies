#include <bits/stdc++.h>

using namespace std;

int main() {

	string s; cin >> s;
	char actual = 'a';
	int n = 'z' - 'a' + 1;
	int total = 0;

	for (int i = 0;i < s.size(); ++i) {
		total += min( abs(s[i]-actual), abs(n - abs(s[i] - actual)) );
		actual = s[i];
	}

	cout << total << endl;

	return 0;
}
