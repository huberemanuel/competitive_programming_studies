#include <bits/stdc++.h>

using namespace std;

int main()
{
	int cases;
	
	cin >> cases;
	
	while (cases--)
	{
		int players, portals, dies;
		map<int, int> portals_map, players_map;
		vector<int> die_rolls;
		
		cin >> players >> portals >> dies;
		
		for (int i = 0; i < players; i++)
			players_map[i + 1] = 1;
		
		for (int i = 0; i < portals; i++)
		{
			int a, b;
			cin >> a >> b;
			portals_map[a] = b;
		}
		
		for (int i = 0; i < dies; i++)
		{
			int a;
			cin >> a;
			die_rolls.push_back(a);
		}
		
		int actual_player = 1;
		for (int i = 0; i < dies; i++, actual_player++)
		{
			
			if (actual_player == (players + 1))
				actual_player = 1;
			
			int pos = players_map[actual_player] + die_rolls[i];
			
			if (portals_map.find(pos) != portals_map.end())
				pos = portals_map[pos];
			
			if (pos > 100)
				pos = 100;			//~ portals_map[b] = a;
			
			players_map[actual_player] = pos;
			
			if (players_map[actual_player] == 100)
				break;
			
		}
		
		for (int i = 0; i < players; i++)
			cout << "Position of player " << i + 1 << " is " << players_map[i + 1] << "." << endl;
		
		
	}
	
	return 0;
}
