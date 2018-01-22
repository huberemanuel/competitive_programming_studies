#include <bits/stdc++.h>

using namespace std;

bool checkString(vector<string> bigger, vector<string> smaller, int x, int y, int m)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (bigger[i + x][j + y] != smaller[i][j])
					return false;
		}	
	}
	
	return true;
}

int main()
{
	int n, m;
	
	while (cin >> n >> m and n and m)
	{
		cin.ignore();
		vector<string> bigger (n, "");
		vector<string> smaller (n, "");
		
		for (int i = 0; i < n; i++)
			{ string s; cin >> s; bigger[i] = s; }
			
		for (int i = 0; i < m; i++)
			{ string s; cin >> s; smaller[i] = s; }
			
		for (int i = 0; i < 4; i++)
		{
			if (i != 0) 
			{
				vector<string> aux (m, "");
				
				for (int j = 0; j < m; j++)
					for (int z = m - 1; z >= 0; z--)
						aux[j] += smaller[z][j];
						
				smaller = aux;
			}
			
			int total = 0;
			
			for (int j = 0; j < n - m + 1; j++)
			{
				for (int z = 0; z < n - m + 1; z++)
				{
					if (bigger[j][z] == smaller[0][0] and checkString(bigger, smaller, j, z, m))
						total++;
				}
			}
			
			cout << total;
			if (i != 3) cout << " ";
			else cout << endl;
		}
		
		
	}
	
	
	return 0;
}
