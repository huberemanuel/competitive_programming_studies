#include <bits/stdc++.h>

using namespace std;

int main()
{
	string moves;
	
	while (getline(cin, moves) and moves != "Game Over")
	{
		int score = 0, tam = static_cast<int>(moves.size()), round_count = 1;
		
		for (int i = 0, aux = 0; i < tam; i++)
		{
			if (moves[i] == ' ') continue;
			if (round_count > 10) break;
			
			if (moves[i] == 'X') 
			{
				aux = 2;
				score += 10;
				if (i + 2 < tam) {
					score += moves[i + 2] == 'X' ? 10 : (moves[i + 2] - '0');
					
				}
				if (i + 4 < tam)
				{
					
					int aux_score;
					if (moves[i + 4] == '/')
						aux_score = 10 - (moves[i + 2] - '0');
					else if (moves[i + 4] == 'X')
						aux_score = 10;
					else 
						aux_score = moves[i + 4] - '0';
					score += aux_score;
				}
			
			}
			
			else if (moves[i] == '/')
			{
				aux++;
				score += 10 - (moves[i - 2] - '0');
				
				if (i + 2 < tam)
					score += moves[i + 2] == 'X' ? 10 : (moves[i + 2] - '0');
			}
			
			else
			{
				score += moves[i] - '0';
				aux++;
			}
			
			if (aux == 2) {
				aux = 0;
				round_count++;
			}
			
		}
		
		cout << score << endl;
		
	}
	
	return 0;
}

