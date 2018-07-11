#include <bits/stdc++.h>

using namespace std;

vector<int> preprocess(string W, bool debug)
{
	vector<int> T (W.length(), 0);

	int i = 1;
	int prefix_len = 0;

	while (i < W.length())
	{
		if (W[i] == W[prefix_len])
			T[i++] = ++prefix_len;
		else
		{
			if (prefix_len > 0)
				prefix_len = T[prefix_len - 1];
			else
				T[i++] = 0;
		}
	}

	if (debug)
	{
		cout << "Table of suffixes and prefixes" << endl;
		for (int item : T)
			cout << item << "\t";
		cout << endl;
	}

	return T;
}

vector<int> KMP(string S, string W, bool debug)
{
	vector<int> positions;

	vector<int> table = preprocess(W, debug);

	int i = 0, j = 0;

	while (i < S.length())
	{
		if (S[i] == W[j])
		{
			i++; j++;
			if (j == W.length())
			{
				positions.push_back(i - j);
				j = table[j - 1];
			}
		}
		else
		{
			if (j > 0)
				j = table[j - 1];
			else
				i++;
		}
	}

	return positions;
}

int main()
{
	string S = "ABC ABCDAB ABCDABCDABDE", W = "ABCDABD";

	vector<int> positions = KMP(S, W, true);

	for (auto i : positions)
	{
		cout << "Found at: " << i << endl;
	}

	return 0;
}
