#include <bits/stdc++.h>

using namespace std;

int main()
{
	int c = 0;
	while (true)
	{
		int n, p;
		cin >> n >> p;
		if (n == 0 and p == 0) break;
		
		if (c > 0) cout << endl;
		c++;
		
		vector<string> reqs;
		
		cin.ignore();
		
		for (int i = 0; i < n; i++)
		{
			string aux;
			getline(cin, aux);
			reqs.push_back(aux);
		}
		
		set<string> s(reqs.begin(), reqs.end());
		
		string r = "";
		double max_compliance = 0, min_value = -1;
		
		for (int i = 0; i < p; i++)
		{
			string aux;
			double v;
			int n_reqs;
			
			getline(cin, aux);
			cin >> v >> n_reqs;
			cin.ignore();
			for (int j = 0; j < n_reqs; j++)
			{
				string req;
				getline(cin, req);
			}
			
			double compliance = n_reqs / (n * 1.0);
			//cout << "debug compliance: " << compliance << endl;
			if (compliance > max_compliance or (compliance == max_compliance and v < min_value))
			{
				r = aux;
				max_compliance = compliance;
				min_value = v;
			}
				
		}
		
		cout << "RFP #" << c << endl;
		cout << r << endl;
		
	}
	
	return 0;
}
