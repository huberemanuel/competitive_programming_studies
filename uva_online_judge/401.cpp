#include <bits/stdc++.h>

using namespace std;

map<char, char> dictionary = {
	{'A', 'A'}, {'H', 'H'},
	{'I', 'I'}, {'M', 'M'},
	{'O', 'O'}, {'T', 'T'},
	{'U', 'U'}, {'V', 'V'},
	{'W', 'W'}, {'X', 'X'},
	{'Y', 'Y'}, {'8', '8'},
	{'E', '3'}, {'3', 'E'}, 
	{'J', 'L'}, {'L', 'J'}, 
	{'S', '2'}, {'2', 'S'}, 
	{'Z', '5'}, {'5', 'Z'},
	{'1', '1'}
	};

string mirrorWord(string word)
{
	for (int i = 0; i < static_cast<int>(word.size()); i++)
		word[i] = dictionary.find(word[i]) != dictionary.end() ? dictionary[word[i]] : ' ';

	return word;
}

int main()
{
	string word, reversed;
	
	while (cin >> word)
	{
		bool palindrome = false, mirrored = false;
		
		reversed = string(word);
		
		reverse(reversed.begin(), reversed.end());
		
		palindrome = word == reversed;
		
		reversed = mirrorWord(word);
		
		reverse(reversed.begin(), reversed.end());
		
		mirrored = word == reversed;
		
		cout << word << " -- is ";
		
		if (not palindrome and not mirrored)
			cout << "not a palindrome." << endl;
		else if (palindrome and not mirrored)
			cout << "a regular palindrome." << endl;
		else if (not palindrome and mirrored)
			cout << "a mirrored string." << endl;
		else
			cout << "a mirrored palindrome." << endl;
		
		cout << endl;
	}
	
	return 0;
}
