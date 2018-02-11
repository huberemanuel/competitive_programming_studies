#include <bits/stdc++.h>

using namespace std;

string from, to;

bool validStrings(string a, string b)
{
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	return a == b;
}

void dfs(string a, string b, string stack, string path, int n) 
{
	
    if(n == static_cast<int>(from.length()) * 2 and b == to) 
    {
		cout << path << endl;
        return;
    }
 
    // push
    if(a.length() > 0)
        dfs(a.substr(1, a.length() - 1), b, 
            stack + a[0], path + (n == 0? "i" : " i"), n + 1);
    // pop
    if(n > 0 and stack.length() > 0 && stack.back() == to[b.length()])
        dfs(a, b + stack.back(), 
            stack.substr(0, stack.length() - 1), 
            path + " o", n + 1);
}

int main()
{
	
	while (cin >> from >> to)
	{
		cout << "[" << endl;
		
		if (validStrings(from, to))
			dfs(from, "", "", "", 0);
		
		cout << "]" << endl;
	}
	
	return 0;
}
