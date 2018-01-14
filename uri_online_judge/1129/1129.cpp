#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	
	while (cin >> n and n)
	{
		int a, b, c, d, e;
		
		for (int i = 0; i < n; i++)
		{
			cin >> a >> b >> c >> d >> e;
			
			if (a < 128 and b > 127 and c > 127 and d > 127 and e > 127)
				cout << "A" << endl;
			else if (a > 127 and b < 128 and c > 127 and d > 127 and e > 127)
				cout << "B" << endl;
			else if (a > 127 and b > 127 and c < 128 and d > 127 and e > 127)
				cout << "C" << endl;
			else if (a > 127 and b > 127 and c > 127 and d < 128 and e > 127)
				cout << "D" << endl;
			else if (a > 127 and b > 127 and c > 127 and d > 127 and e < 128)
				cout << "E" << endl;
			else
				cout << "*" << endl;
		}
		
	}
	
	return 0;
}
