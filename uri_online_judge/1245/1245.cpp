#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	
	while (cin >> n)
	{
		map<int, int> E, D;
		
		for (int i = 0; i < n; i++)
		{
			int a;
			char b;
			
			cin >> a >> b;
			cin.ignore();
			
			if (b == 'E')
				E[a]++;
			else
				D[a]++;
		}
		
		int total = 0;
		
		for (map<int, int>::iterator it = E.begin(); it != E.end() ; it++)
		{
			if (D.find(it->first) != D.end())
				total += min(D[it->first], it->second);
		}
		
		cout << total << endl;
		
	}
	
	return 0;
}
