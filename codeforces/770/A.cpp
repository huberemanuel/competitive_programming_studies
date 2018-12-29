#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, k; cin >> n >> k;
	string s;
	char c;
	for (int i = 0,c = 'a'; i < n; ++i, ++c) {
		if (c >= ('a'+k)) c = 'a';
		s.push_back(c);
	}

	cout << s << endl;

	return 0;
}

