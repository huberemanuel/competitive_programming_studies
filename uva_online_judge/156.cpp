#include <bits/stdc++.h>

using namespace std;

int main()
{
	string read;
	vector<string> original;
	vector<string> lower_case;
	vector<string> solution;
	map<string, int> ananagrams;
	
	while (cin >> read and read != "#")
	{
		original.push_back(read);
		
		string aux = "";
		for (int i = 0; i < static_cast<int>(read.length()); i++)
			if (tolower(read[i]) >= 'a' and tolower(read[i]) <= 'z')
				aux += tolower(read[i]);
		
		sort(aux.begin(), aux.end());
		
		lower_case.push_back(aux);
		
		ananagrams[aux]++;
	}
	
	for (int i = 0; i < static_cast<int>(lower_case.size()); i++)
		if (ananagrams[lower_case[i]] == 1)
			solution.push_back(original[i]);
	
	sort(solution.begin(), solution.end());
	
	for (int i = 0; i < static_cast<int>(solution.size()); i++)
		cout << solution[i] << endl;
	
	return 0;
}
