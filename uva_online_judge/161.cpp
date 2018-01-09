#include <bits/stdc++.h>

using namespace std;

int main()
{
	while (true)
	{
		vector<int> pos(3);
		
		cin >> pos[0] >> pos[1] >> pos[2];
		
		if (count(pos.begin(), pos.end(), 0) == 3)
			break;
			
		while (pos.back() != 0)
		{
			int a;
			cin >> a;
			pos.push_back(a);
		}
		
		int lowest = *min_element(pos.begin(), pos.end() - 1);
		
		int i = 0;
		
		for (i = lowest * 2; i < 18001; i++)
		{
			bool flag = true;
			for (int j = 0; j < static_cast<int>(pos.size()) - 1; j++)
			{
				if (i % (2 * pos[j]) >= pos[j] - 5) 
				{			
					flag = false;
					break;
				}
			}
			if (flag)
			{
				int h = i / 3600;
				int m = (i - h * 3600) / 60;
				int s = i - h * 3600 - m * 60;
				printf("%02d:%02d:%02d\n", h, m, s);
				break;
			}
		}
		
		if (i == 18001)
			cout << "Signals fail to synchronise in 5 hours" << endl;
	}
	
	return 0;
}
