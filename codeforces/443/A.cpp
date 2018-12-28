#include <bits/stdc++.h>

using namespace std;

int main()
{
	set<char> S;
	char c;
	while (true) {
		c = getchar();
		if (c == '}') break;
		if (c >= 'a' and c <= 'z')
			S.insert(c);
	}

	cout << S.size() << endl;

	return 0;
}
