#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int main()
{
	vector<ull> numbers;
	int aux;
	
	while (cin >> aux)
	{
		numbers.push_back(aux);
		sort(numbers.begin(), numbers.end());
		
		int tam = static_cast<int>(numbers.size());
		ull res;
		
		if (tam % 2 == 0)
			res = (numbers[ceil(tam / 2)] + numbers[ceil(tam / 2) - 1]) / 2;
		else
			res = numbers[ceil(tam / 2)];
		
		cout << res << endl;
	}	
	
	return 0;
}
