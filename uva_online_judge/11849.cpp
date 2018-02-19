#include<bits/stdc++.h>

using namespace std;

int main()
{
	int N, M;
	
	while (cin >> N >> M, N || M)
	{
		set<int> S;
		int cont = 0;
		
		for (int i = 0; i < N; i++)
		{
			int a; cin >> a; S.insert(a);
		}
		
		for (int i = 0; i < M; i++)
		{
			int a; cin >> a; 
			if (S.find(a) != S.end())
				cont++;
		}
		
		cout << cont << endl;
	}
	
	
	return 0;
}
