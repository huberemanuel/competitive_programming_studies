#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s;

	getline(cin, s);

	int up = 0, low = 0;

	for (int i = 0; i < s.size(); ++i) {
		if (s[i] >= 'a' and s[i] <= 'z')
			low++;
		else
			up++;
	}

	for (int i = 0; i < s.size(); ++i) {
		if (low >= up and s[i] >= 'A' and s[i] <= 'Z') 
			s[i] += 32;
		else if (low < up and s[i] >= 'a' and s[i] <= 'z')
			s[i] -= 32;

	}

	cout << s << endl;

	return 0;
}

