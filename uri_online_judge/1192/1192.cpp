#include <bits/stdc++.h>

using namespace std;

int main()
{
	int cases;
	
	cin >> cases;
	
	while (cases--)
	{
		int a, b;
		char c;
		
		cin >> a >> c >> b;
		
		if (a == b)
			cout << a * b << endl;
		else if (c >= 'A' and c <= 'Z')
			cout << b - a << endl;
		else 
			cout << a + b << endl;
	}
	
	
	return 0;
}
