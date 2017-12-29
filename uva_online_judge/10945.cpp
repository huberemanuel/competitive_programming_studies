#include <bits/stdc++.h>

using namespace std;

int main()
{
	string sentence;
	
	while (getline(cin, sentence) and sentence != "DONE")
	{
		string aux = "", aux_reversed;
		
		for (int i = 0; i < static_cast<int>(sentence.size()); i++)
		{
			if (tolower(sentence[i]) >= 'a' and tolower(sentence[i]) <= 'z')
				aux += tolower(sentence[i]);
		}
		
		aux_reversed = string(aux);
		
		reverse(aux_reversed.begin(), aux_reversed.end());
		
		if (aux == aux_reversed)
			cout << "You won’t be eaten!" << endl;
		else
			cout << "Uh oh.." << endl;
	}

	return 0;
}

