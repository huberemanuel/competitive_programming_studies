#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

vector< pii > sides;
int grid[3][3];
int grid_aux[3][3];

bool solved()
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (grid[i][j]) return false;
	return true;
}

int f()
{
	if (solved()) return 0;
	
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			grid[i][j] = 0;
			for(auto p : sides) {
				if(j + p.first >= 0 && j + p.first < 3 &&
				   i + p.second >= 0 && i + p.second < 3) {
					grid[i][j] ^= grid_aux[i + p.second][j + p.first];
				}
		    }
		}
	}
	
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			grid_aux[i][j] = grid[i][j];
	
	return f() + 1;
}

int main()
{
	int n;
	char c;
	
	sides.push_back(make_pair(0, 1));
    sides.push_back(make_pair(0, -1));
    sides.push_back(make_pair(1, 0));
    sides.push_back(make_pair(-1, 0));

	cin >> n;
	
	while (n--)
	{
		scanf("\n");
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
			{
				cin >> c;
				grid[i][j] = c - '0';
				grid_aux[i][j] = c - '0';
			}
		
		cout << f() - 1 << endl;
	}
	
	
	return 0;
}

