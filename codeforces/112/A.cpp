#include <bits/stdc++.h>

using namespace std;

int main()
{
	char a[101], b[101];

	scanf(" %[^\n]", a);
	scanf(" %[^\n]", b);

	for (int i = 0; a[i] != '\0'; ++i) {
		if (a[i] >= 'a' and a[i] <= 'z')
			a[i] -= 32;
		if (b[i] >= 'a' and b[i] <= 'z')
			b[i] -= 32;
	}

	int res = strcmp(a, b);
	cout << (res < 0 ? -1: (res > 0 ? 1 : 0)) << endl;

	return 0;
}
