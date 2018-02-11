#include <bits/stdc++.h>

using namespace std;

#define MAX 1000001

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m;
	
	while (cin >> n >> m, n || m)
	{
		bool conflict = false;
		
		bitset<MAX> timeline (0);
		
		for (int i = 0; i < n; i++)
		{
			int begin, end;
			cin >> begin >> end;
			
			if (conflict) continue;
			
			if (end < begin)
				swap(begin, end);
			
			for (; begin < end and !conflict; begin++)
			{
				conflict = timeline[begin];
				timeline.set(begin);
			}
		}
		
		for (int i = 0; i < m; i++)
		{
			unsigned long long begin, end, rate;
			cin >> begin >> end >> rate;
			
			if (conflict) continue;
			
			if (end < begin)
				swap(begin, end);
				
			int new_begin = begin;
			int new_end = end;
			
			while (new_begin < MAX and !conflict)
			{
				for (int k = new_begin; k < new_end and k < MAX and !conflict; k++)
				{
					conflict = timeline[k];
					timeline.set(k);
				}
				new_begin += rate;
				new_end += rate;
			}
		}
		
		if (!conflict) cout << "NO ";
		cout << "CONFLICT" << endl;
		
	}
	
	
	return 0;
}
