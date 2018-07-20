#include <bits/stdc++.h>

using namespace std;

int mdc(int a, int b) {
	if (b == 0) return a;
	return mdc(b, a % b);
}

int main()
{
	vector<int> v(3);

	while (cin >> v[0] >>v[1] >> v[2])
	{
		sort(v.begin(), v.end());
		if (v[2]*v[2]==(v[0]*v[0]+v[1]*v[1])) {
			if (mdc(mdc(v[0], v[1]), v[2]) == 1)
				cout << "tripla pitagorica primitiva" << endl;
			else
				cout << "tripla pitagorica" << endl;
		}
		else
			cout << "tripla" << endl;
	}

	return 0;
}
