#include <bits/stdc++.h>

#define MAX 1000

using namespace std;

int M[MAX][MAX], N;

bool isBipartite()
{
	int visiteds[N];
	memset(visiteds, 0, sizeof(visiteds));
	stack<int> S;
	int cor = 1;

	S.push(0);

	while (!S.empty())
	{
		int atual = S.top();

		if (visiteds[atual] == 0)
		{
			visiteds[atual] = cor;
			cor = 1 + cor % 2;
		}
		
		bool flag = false;
		for (int i = 0; i < N; ++i)
		{
			if (M[atual][i] == 0 && visiteds[i] == 0)
			{
				S.push(i);
				flag = true;
			}
			else if (M[atual][i] == 0)
				if (visiteds[i] == visiteds[atual])
					return false;
		}
		if (!flag)
		{
			S.pop();
		}
	}

	return true;
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; ++i)
		for (int j = 0;j < N; ++j)
			cin >> M[i][j];

	if (isBipartite())
		cout << "Bazinga!" << endl;
	else
		cout << "Fail!" << endl;
	
	return 0;
}
