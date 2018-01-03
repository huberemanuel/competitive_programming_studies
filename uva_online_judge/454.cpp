#include <bits/stdc++.h>

using namespace std;

string lower(string a)
{
	string aux = "";
	int tam = static_cast<int>(a.length());
	
	for (int i = 0; i < tam; i++)
		if (a[i] != ' ')
			aux += a[i];
			
	sort(aux.begin(), aux.end());
			
	return aux;
}

int main()
{
	int cases;
	string sentence, read;
	
	cin >> cases;
	
	cin.ignore();
    cin.ignore();
	
	while (cases--)
	{
		string sentence = "";
		vector<string> original;
		map<string, string> lower_case;
		
		while (getline(cin, read) and read != "")
		{
			original.push_back(read);

			lower_case[read] = lower(read);
		}
		
		sort(original.begin(), original.end());
		
		for (int i = 0; i < static_cast<int>(original.size()); i++)
		{

			for (int j = i + 1; j < static_cast<int>(original.size()); j++)
			{
				if (lower_case[original[i]] == lower_case[original[j]])
					cout << original[i] << " = " << original[j] << endl;
			}
			
		}
		
		if (cases)
			cout << endl;
	}

	return 0;
}

