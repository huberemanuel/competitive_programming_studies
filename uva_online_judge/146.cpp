#include <bits/stdc++.h>

using namespace std;

int main()
{
	string code;
	
	while (cin >> code and code != "#")
	{
		if (not	next_permutation(code.begin(), code.end()))
			cout << "No Successor" << endl;
		else 
			cout << code << endl;
	}
	
	return 0;
}
