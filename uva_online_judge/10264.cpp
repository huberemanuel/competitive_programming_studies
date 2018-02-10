#include <bits/stdc++.h>

using namespace std;

bool neighbors(int a, int b)
{
	int aux = a ^ b;
	return (aux & (-aux)) == aux;
}

int main()
{
	int n;
	
	while (cin >> n)
	{
		vector<int> potencies ((1 << 15), 0);
		int max_value = 0;
		for (int i = 0; i < (1 << n); i++)
		{
			int x;
			cin >> x;
			
			for (int j = 0; j < (1 << n); j++)
				if (neighbors(i, j) and i != j)
					potencies[j] += x;
		}
		
		for(int i = 0; i < (1 << n); i++) 
		{
			for(int j = 0; j < (1 << n); j++) 
			{
				if(!neighbors(i, j) || i == j) continue;
				max_value = max(max_value, potencies[i] + potencies[j]);
			}
		}
		
		cout << max_value << endl;
	}
	
	return 0;
}
