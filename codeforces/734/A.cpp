#include <bits/stdc++.h>

using namespace std;

int main()
{
	int A; cin >> A;
	string S;
	cin.ignore();
	getline(cin, S);

	size_t a = count(S.begin(), S.end(), 'A');
	size_t d = count(S.begin(), S.end(), 'D');

	if (a == d) cout << "Friendship" << endl;
	else if (a > d) cout << "Anton" << endl;
	else cout << "Danik" << endl;

	return 0;
}
