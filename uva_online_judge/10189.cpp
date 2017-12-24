
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int m, n, cases = 1;
	
	while(cin >> m >> n and (m != 0 and n != 0))
	{
		int game[m][n];
		
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				char c;
				cin >> c;
				game[i][j] = c == '*' ? -1 : 0;
			}
		}
		
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (game[i][j] != -1) continue;
				
				if (i + 1 < m and game[i + 1][j] != -1)
					game[i + 1][j]++;
					
				if (j + 1 < n and game[i][j + 1] != -1)
					game[i][j + 1]++;
					
				if (i - 1 >= 0 and game[i - 1][j] != -1)
					game[i - 1][j]++;
					
				if (j - 1 >= 0 and game[i][j - 1] != -1)
					game[i][j - 1]++;
						
				if (i + 1 < m and j + 1 < n and game[i + 1][j + 1] != -1)
					game[i + 1][j + 1]++;
					
				if (i + 1 < m and j - 1 >= 0 and game[i + 1][j - 1] != -1)
					game[i + 1][j - 1]++;
					
				cout << ((i - 1 >= 0 and j + 1 < n and game[i - 1][j + 1] != -1) ? "true" : "false") << endl;
					
				if (i - 1 >= 0 and j + 1 < n and game[i - 1][j + 1] != -1)
					game[i - 1][j + 1]++;
					
				if (i - 1 >= 0 and j - 1 >= 0 and game[i - 1][j - 1] != -1)
					game[i - 1][j - 1]++;

			}
		}
		
		cout << "Field #" << cases++ << ":" << endl;
		
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << (game[i][j] == -1 ? "*" : to_string(game[i][j]));
			}
			cout << endl;
		}
	}
	
	return 0;
}


