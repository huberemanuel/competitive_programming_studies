#include <bits/stdc++.h>

using namespace std;

bool compare(char a, char b)
{
	bool lowerA, lowerB;
	
	lowerA = a >= 'a' and a <= 'z';
	lowerB = b >= 'a' and a <= 'z';
	
	if ((lowerA and lowerB) or (!lowerA and !lowerB))
		return a < b;
	
	if (lowerA)
    {
        a -= ('a'-'A');
        return a < b;
    }
    else
    {
        b -= ('a'-'A');
        return a <= b;
    }
}

int main()
{
	int n;
	
	cin >> n;
	
	while (n--)
	{
		string word;
		
		cin >> word;
		
		sort(word.begin(), word.end(), compare);
		
		do
		{
			cout << word << endl;
		} while (next_permutation(word.begin(), word.end(), compare));
		
	}
	
	return 0;
}
