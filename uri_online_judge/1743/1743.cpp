#include <bits/stdc++.h>

using namespace std;

int main()
{
	vector<int> X;
	vector<int> Y;
	
	for (int i = 0; i < 5; i++) {
		int a; cin >> a; X.push_back(a);
	}
		
	for (int i = 0; i < 5; i++) {
		int a; cin >> a; Y.push_back(a);
	}
		
	bool flag = true;
		
	for (int i = 0; i < 5 and flag; i++)
		flag = X[i] != Y[i];
		
	cout << (flag ? "Y" : "N") << endl;
	
	return 0;
}
