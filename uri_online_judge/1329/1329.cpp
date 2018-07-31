#include <bits/stdc++.h>

using namespace std;


int main()
{
	int n, aux;

	while (cin >> n, n)
	{
		map<int, int> m;
		while (n--) cin >> aux, m[aux]++;
		printf("Mary won %d times and John won %d times\n", m[0], m[1]);
	}

	return 0;
}
