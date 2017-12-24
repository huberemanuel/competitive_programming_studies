
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int r;
	
	while (cin >> r and r >= 0)
	{
		int errors = 0;
		bool win = true;
		string begin, end;
		map<char, int> word;
		map<char, int> guess;
		cin >> begin;
		cin >> end;
		
		for (int i = 0; i < static_cast<int>(begin.size()); i++)
			word[begin[i]] = 0;
			
		for (int i = 0; i < static_cast<int>(end.size()); i++)
			guess[end[i]] = 0;
			
		for (int i = 0; i < static_cast<int>(end.size()); i++)
		{
			if (word.find(end[i]) == word.end())
			{
				if (guess[end[i]] == 0)
				{
					++errors;
				}
				guess[end[i]]++;
			}
			if (errors >= 7) break;
			
			word[end[i]]++;
		}
		
		for (map<char, int>::iterator it = word.begin(); it != word.end(); ++it)
			if (it->second == 0)
				win = false;
		
		cout << "Round " << r << endl;
		
		if (win)
			cout << "You win." << endl;
		else if (errors >= 7)
			cout << "You lose." << endl;
		else
			cout << "You chickened out." << endl;
		
	}
	
		
	return 0;
}

