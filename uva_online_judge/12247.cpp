#include <bits/stdc++.h>

using namespace std;

int main()
{
	vector<int> daughter(3);
	vector<int> son(2);
	
	while (cin >> daughter[0] >> daughter[1] >> daughter[2] >> son[0] >> son[1] 
			and daughter[0] and daughter[1] and daughter[2] and son[0] and son[1])
	{
		int card = 53;
		sort(daughter.begin(), daughter.end());
		sort(son.begin(), son.end());
			
		if (son[0] > daughter[2])
		{
			for (int i = 1; i < 53; i++)
			{
				if (find(daughter.begin(), daughter.end(), i) == daughter.end() and find(son.begin(), son.end(), i) == son.end())
				{
					card = i;
					break;
				}
			}
		}
		
		else if (son[0] > daughter[1])
		{
			for (int i = daughter[1] + 1; i < 53; i++)
			{
				if (find(daughter.begin(), daughter.end(), i) == daughter.end() and find(son.begin(), son.end(), i) == son.end())
				{
					card = i;
					break;
				}
			}
		}
		
		else if (son[1] > daughter[2])
		{
			for (int i = daughter[2] + 1; i < 53; i++)
			{
				if (find(daughter.begin(), daughter.end(), i) == daughter.end() and find(son.begin(), son.end(), i) == son.end())
				{
					card = i;
					break;
				}
			}
		}
		
		cout << (card == 53 ? -1 : card) << endl;
	}
	
	return 0;
}
