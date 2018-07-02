#include <bits/stdc++.h>

using namespace std;

const vector<string> split(const string& s, const char& c)
{
	string buff{""};
	vector<string> v;
	
	for(auto n:s)
	{
		if(n != c) buff+=n; else
		if(n == c && buff != "") { v.push_back(buff); buff = ""; }
	}
	if(buff != "") v.push_back(buff);
	
	return v;
}

int main()
{
	int cases;

	cin >> cases;
	cin.ignore();

	while (cases--)
	{
		set<string> S;
		string aux;
		getline(cin, aux);
		for (string s : split(aux, ' '))
			S.insert(s);

		unsigned int i = 0;
		for (string it : S)
		{
			cout << it;
			if (i++ != S.size() - 1)
				cout << " ";
		}

		cout << endl;


	}
	return 0;
}
