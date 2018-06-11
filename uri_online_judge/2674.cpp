#include <bits/stdc++.h>

using namespace std;

bool is_prime(int n)
{
	if (n < 2) return false;
	if (n % 2 == 0) return n == 2;
	int root = (int) sqrt(n);
	for (int i = 3; i <= root; i += 2)
		if (n % i == 0) return false;
	return true;
}

int main()
{

	int n;

	while (cin >> n)
	{
		if (is_prime(n))
		{
			bool is_super = true;
			while (n > 0)
			{
				int r = n % 10;
				n = n / 10;
				is_super = is_prime(r);
				if (not is_super) break;
			}
			if (is_super)
				cout << "Super" << endl;
			else
				cout << "Primo" << endl;
		}
		else
			cout << "Nada" << endl;
	}

	return 0;
}
