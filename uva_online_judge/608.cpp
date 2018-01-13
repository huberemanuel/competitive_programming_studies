#include <bits/stdc++.h>

using namespace std;

int main()
{
	int cases;
	
	cin >> cases;
	
	cin.ignore();
	
	while (cases--)
	{
		vector<string> left, right, level;
		map<char, int> cont;
		
		for (int i = 0; i < 3; i++)
		{
			string a, b, c;
			
			cin >> a >> b >> c;
			left.push_back(a);
			right.push_back(b);
			level.push_back(c);
			
			if (c == "even")
				for (int j = 0; j < static_cast<int>(a.length()); j++)
				{
					cont[a[j]] = 1;
					cont[b[j]] = 1;
				}
				
		}
		
		string ans_char = "", ans_weight;
		
		bool flag = false;
		for (unsigned int i = 0; i < level.size() and not flag; i++)
		{
			
			if (level[i] != "even")
			{
				for (unsigned int j = 0; j < left[i].size(); j++)
				{
					if (cont.find(left[i][j]) == cont.end())
					{
						ans_char += left[i][j];
						ans_weight = (level[i] == "up" ? "heavy" : "light");
						flag = true;
						break;
					}
				}
				
				for (unsigned int j = 0; j < right[i].size() and not flag; j++)
				{
					if (cont.find(right[i][j]) == cont.end())
					{
						ans_char += right[i][j];
						ans_weight = (level[i] == "up" ? "light" : "heavy");
						flag = true;
					}
				}
				
			}
		}
		
		cout << ans_char << " is the counterfeit coin and it is " << ans_weight << "." << endl;
		
	}
	
	
	return 0;
}
