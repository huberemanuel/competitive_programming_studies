#include <bits/stdc++.h>

using namespace std;

int main()
{
	int cases;
	
	cin >> cases;
	
	while (cases--)
	{
		char c;
		int ans, m, n;
		
		cin >> c >> m >> n;
		
		switch (c)
		{
			case 'r':
				ans = min(m, n);
				break;
			case 'k':
				ans = (m * n) % 2 == 0 ? (m * n) / 2 : (m * n + 1) / 2;
				break;
			case 'Q':
				ans = min(m, n);
				break;
			case 'K':
				ans = (m % 2 == 0 ? m : m + 1) / 2 * (n % 2 == 0 ? n : n + 1) / 2;
				break;
		}
		
		cout << ans << endl;
		
	}

	return 0;
}

