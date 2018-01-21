#include <bits/stdc++.h>

using namespace std;

int main()
{
	int s, b;
	
	while (cin >> s >> b and s and b)
	{
		vector<bool> soldiers (s, true);
		
		while (b--)
		{
			int begin, end;
			
			cin >> begin >> end;
			
			for (int i = begin - 1; i < end; i++)
				soldiers[i] = false;
			
			int left = -1, right = -1;
			
			for (int i = begin - 1; i >= 0; i--)
				if (soldiers[i])
				{
					left = i + 1;
					break;
				}
					
			for (int i = end; i < static_cast<int>(soldiers.size()); i++)
				if (soldiers[i])
				{
					right = i + 1;
					break;
				}
				
			if (left == -1) cout << "* ";
			else cout << left << " ";
			
			if (right == -1) cout << "*";
			else cout << right;
			
			cout << endl;
		}
		
		
		cout << "-" << endl;
	}
	
	
	return 0;
}
