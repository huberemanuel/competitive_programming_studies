#include <bits/stdc++.h>

using namespace std;

int main()
{
	std::map<char, int> suitConversion;
    suitConversion['S'] = 0;
    suitConversion['H'] = 1;
    suitConversion['D'] = 2;
    suitConversion['C'] = 3;
    
	char back[4] = {'S', 'H', 'D', 'C'};

	string aux;
	
	bool ace[4], king[4], queen[4], jack[4], trump[4];
	int count[4], points, specialPoints, pos;
	
	while(cin >> aux)
	{
		memset(ace, 0, sizeof(bool) * 4);
		memset(king, 0, sizeof(bool) * 4);
		memset(queen, 0, sizeof(bool) * 4);
		memset(jack, 0, sizeof(bool) * 4);
		memset(trump, 0, sizeof(bool) * 4);
		memset(count, 0, sizeof(int) * 4);
		
		points = specialPoints = 0; 
		
		for (int i = 0; i < 13; ++i)
		{
			if (i != 0)
				cin >> aux;
				
			pos = suitConversion[aux[1]];
			
			switch (aux[0])
			{
				case 'A':
					ace[pos] = true;
					points += 4;
					break;
				case 'K':
					king[pos] = true;
					points += 3;
					break;
				case 'Q':
					queen[pos] = true;
					points += 2;
					break;
				case 'J':
					jack[pos] = true;
					points += 1;
					break;
					
			}
		
			++count[pos];
			
		}
		
		for (int i = 0; i < 4; ++i)
		{
			if (ace[i])
				trump[i] = true;
			
			if (count[i] < 2 and king[i])
				points--;
				
			else if (king[i])
				trump[i] = true;
				
			if (queen[i] and count[i] < 3)
				points--;
				
			else if (queen[i])
				trump[i] = true;
				
			if (jack[i] and count[i] < 4)
				--points;
			
			if (count[i] == 2)
                ++specialPoints;
            
            else if (count[i] < 2)
				specialPoints += 2;
			
		}
		
		if (trump[0] and trump[1] and trump[2] and trump[3] and points >= 16)
			cout << "BID NO-TRUMP" << endl;
		
		else if (points + specialPoints >= 14) 
		{
			int max_i = 0, max_count = 0;
			for (int i = 0; i < 4; i++)
			{
				if (count[i] > max_count) 
				{
					max_count = count[i];
					max_i = i;
				}
			}
			
			cout << "BID " << back[max_i] << endl;
		}
			
		else
			cout << "PASS" << endl;
		
	}
	
	return 0;
}
