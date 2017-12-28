#include <bits/stdc++.h>

using namespace std;

map<char, char> anti = {{'R', 'P'}, {'P', 'S'}, {'S', 'R'}};
int di[]={1,-1,0,0};
int dj[]={0,0,1,-1};

char returnWinner(char a, char b)
{
	char winner;
	switch (a)
	{
		case 'S':
			winner = b == 'R' ? b : a;
			break;
		case 'R':
			winner = b == 'P' ? b : a;
		default:
			winner = b == 'S' ? b : a;
			
	}
	return winner;
}

int main()
{
	int cases;
	
	cin >> cases;
	
	for (int k = 0; k < cases; k++)
	{
		if (k > 0)
			cout << endl;
		
		int m, n, days;
		
		cin >> m >> n >> days;

		vector<string> grid;
		vector<string> grid_aux;
		
		grid.clear();
		
		for (int i = 0; i < m; ++i)
		{
			string aux;
			cin >> aux;
			grid.push_back(aux);
			grid_aux.push_back(aux);
		}	
		
		while (days--)
		{
			
			grid_aux.clear();
			
			for (int i = 0; i < m; i++)
			{
				string s = "";
				for (int j = 0; j < n; j++)
				{	
					char aux = '1';
					
					for (int z = 0; z < 4; z++)
					{
						int I = i + di[z];
						int J = j + dj[z];
						
						if(I >= 0 and I < m and J >= 0 and J < n and grid[I][J] == anti[grid[i][j]]) 
						{
							aux = anti[grid[i][j]];
							break;
						}
					}
					
					aux = aux == '1' ? grid[i][j] : anti[grid[i][j]];
					
					s += aux;

				}
				
				grid_aux.push_back(s);
				
			}
			
			grid = grid_aux;
			
		}
		
		for (int i = 0; i < m; i++)
			cout << grid[i] << endl;

	}
		
	return 0;
}

