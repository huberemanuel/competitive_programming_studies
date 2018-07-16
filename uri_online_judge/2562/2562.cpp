#include <bits/stdc++.h>

#define MAX 1000

using namespace std;

int dfs(int m[][MAX], int n, int search)
{
	stack<int> S;
	vector<int> V;
	int count = 0;

	S.push(search);
	V.push_back(search);

	while (not S.empty())
	{
		int actual = S.top();
		count++;
		S.pop();

		for (int i = 0; i < n; ++i)
		{
			if (m[actual][i] == 1 and find(V.begin(), V.end(), i) == V.end())
			{
				S.push(i);
				V.push_back(i);
			}
		}
	}


	return count;
}

int main()
{
	int N, M;

	while (cin >> N >> M)
	{
		int m[MAX][MAX];
		memset(m, 0, sizeof(m));

		for (int i = 0; i < M; ++i)
		{
			int from, to;
			cin >> from >> to;
			m[from - 1][to - 1] = 1;
			m[to - 1][from - 1] = 1;
		}

		int specie;
		cin >> specie;
		cout << dfs(m, N, specie - 1) << endl;
	}

	return 0;
}
