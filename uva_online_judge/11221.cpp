#include <bits/stdc++.h>

using namespace std;

int main()
{
	int cases;
	
	cin >> cases;
	cin.ignore();
	
	for (int c = 0; c < cases; c++)
	{
		string aux, sentence = "";
		bool magic;
		int tam;
		double frac_part;
		
		getline(cin, aux);
		
		for (int i = 0; i < static_cast<int>(aux.size()); i++)
			if (tolower(aux[i]) >= 'a' and tolower(aux[i]) <= 'z')
				sentence += tolower(aux[i]);
		
		tam = static_cast<int>(sentence.size());
		
		string reversed = string(sentence);
		reverse(reversed.begin(), reversed.end());
		
		int squared = sqrt(tam);
		magic = modf(sqrt(tam), &frac_part) == 0.0 and reversed == sentence;
		
		for (int i = 0, z = 0; i < squared and magic; i++)
			for (int j = 0; j < squared; j++) {
				if (sentence[j * squared + i] != sentence[z++])
					magic = false;
			}
				
		for (int i = squared - 1, z = tam - 1; i >= 0 and magic; i--)
			for (int j = squared - 1; j >= 0; j--) {
				if (sentence[j * squared + i] != sentence[z--])
					magic = false;
			}
		
		for (int i = squared - 1, z = tam - 1; i >= 0 and magic; i--)
			for (int j = squared - 1; j >= 0; j--)
				if (sentence[i * squared + j] != sentence[z--])
					magic = false;
		
		cout << "Case #" << c + 1 << ":" << endl;
		if (not magic)
			cout << "No magic :(" << endl;
		else
			cout << squared << endl;
	}
	
	return 0;
}

