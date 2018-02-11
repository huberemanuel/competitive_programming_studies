#include <bits/stdc++.h>

using namespace std;

int foo(vector<int> indexes, int n, int i)
{
	int num = 0;
	for (; i < static_cast<int>(indexes.size()); i += 2)
	{
		num = num | (1 << indexes[i]);
	}
	return num;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	
	while (cin >> n, n)
	{
		vector<int> indexes;
		
		for (int i = 0; i < 32; i++)
		{
			if (((1 << i) & n) == (1 << i))
				indexes.push_back(i);
		}
		
		cout << foo(indexes, n, 0) << " " << foo(indexes, n, 1) << endl;
		
	}
	
	
	return 0;
}
