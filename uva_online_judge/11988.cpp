#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string text;
	
	while (cin >> text)
	{
		stack<int> pos;
		list<char> text_list;
		auto it = text_list.begin();
		
		for (int i = 0; i < static_cast<int>(text.size()); i++)
		{
			if (text[i] == '[')
				it = text_list.begin();
			else if (text[i] == ']')
				it = text_list.end();
			else
				text_list.insert(it, text[i]);
		}
		
		for (it = text_list.begin(); it != text_list.end(); it++)
			cout << *it;
		cout << endl;
	}
	
	return 0;	
}
