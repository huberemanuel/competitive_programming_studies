#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	string ans;
	
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		string aux;
		vector<string> cards;
		
		for (int j = 0; j < 52; j++)
		{
			cin >> aux;
			cards.push_back(aux);
		}
		
		ans = cards[32];
		
		cout << "Case " << i + 1 << ": " << ans << endl;
	}
		
	return 0;
}

