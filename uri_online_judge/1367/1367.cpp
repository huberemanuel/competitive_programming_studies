#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;

	while (cin >> n, n)
	{
		int corrects = 0, total = 0;
		map<char, int> m;

		while (n--)
		{
			char a; int b; string c;
			cin >> a >> b >> c;
			if (c == "incorrect") m[a] += 20;
			else m[a] += b, total += m[a], corrects++;
		}

		cout << corrects << " " << total << endl;
	}

	return 0;
}
