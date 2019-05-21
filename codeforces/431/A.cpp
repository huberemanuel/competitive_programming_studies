#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long 

int main() {

	map<char, ull> a;

	for (int i = 0; i < 4; ++i) {
		ull aux; cin >> aux;
		a['1'+i] = aux;
	}

	string s; cin >> s;
	ull total = 0;
	for (int i = 0;i < s.size(); ++i) {
		total += a[s[i]];
	}

	cout << total << endl;

	return 0;
}
