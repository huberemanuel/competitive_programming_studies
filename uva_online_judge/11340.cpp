#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	
	cin >> n;
	
	while (n--)
	{
		int k;
		map<char, int> values;
		
		cin >> k;
		
		while (k--)
		{
			char a;
			int b;
			cin >> a >> b;
			cin.ignore();
			values[a] = b;
			//~ cout << "	values[" << a << "] = " << b << endl;
		}
		
		int m;
		int total = 0;
		
		cin >> m;
		cin.ignore();
		
		while (m--)
		{
			string a;
			getline(cin, a);
			//~ cout << a << endl;	
			for (unsigned int i = 0; i < a.size(); i++)
			{
				//~ if (values.find(a[i]) != values.end())
				//~ {
					total += values[a[i]];
					//~ cout << "total += " << values[a[i]] << " char " << a[i] << endl;
				//~ }
					
			}
			
		}
		
		printf("%0d.%02d$\n", (int)ceil(total / 100), total % 100);
		
		//~ cin.ignore();
		
	}
	
	
	
	return 0;
}
