#include <bits/stdc++.h>

using namespace std;

int main()
{
	int cases;
	map<int, int> numbers;
	
	cin >> cases;
	
	while (cases--)
	{
		int a;
		
		cin >> a;
		
		numbers[a]++;
	}
	
	for (map<int, int>::iterator it = numbers.begin(); it != numbers.end() ; it++)
	{
		cout << it->first << " aparece " << it->second << " vez(es)" << endl;
	}
	
		
	return 0;
}

