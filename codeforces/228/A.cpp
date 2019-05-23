#include <bits/stdc++.h>

using namespace std;

int main() {

	set<int> S;

	int a, b, c, d; cin >> a >> b >> c >> d;
	S.insert(a); S.insert(b); S.insert(c); S.insert(d);

	cout << 4 - static_cast<int>(S.size()) << endl;

	return 0;
}
