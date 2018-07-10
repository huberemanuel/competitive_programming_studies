#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	
	cin >> n;
	
	while (n--)
	{
		string str;
		priority_queue< string, vector<string>, greater<string> > pq;
		
		cin >> str;
		sort(str.begin(), str.end());
		
		do
		{
			pq.push(str);
		} while( next_permutation(str.begin(), str.end()) );
		
		while (not pq.empty())
		{
			cout << pq.top() << endl;
			pq.pop();
		}
		cout << endl;
		
	}
	
	return 0;
}
