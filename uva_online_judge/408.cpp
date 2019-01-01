#include <bits/stdc++.h>

using namespace std;

int main()
{
	int step, mod;

	while (cin >> step >> mod) {
		char res[15];
		int cnt = 0, rand = 0;
		while (cnt != mod) {
			rand = (rand + step) % mod;
			cnt++;
			if (rand == 0) break;
		}

		if (cnt == mod) strcpy(res, "Good Choice");
		else strcpy(res, "Bad Choice");

		printf("%10d%10d    %s\n\n", step, mod, res);

	}
	return 0;
}
