#include <bits/stdc++.h>

using namespace std;

int main()
{
	int SET;
	
	cin >> SET;
	
	while (SET--)
	{
		int N, S, Q, n_cargos = 0, time = 0;
		stack<int> fork_lift;
		
		cin >> N >> S >> Q;
		
		vector<queue<int>> containers;
		queue<int> empty_queue;
		cin.ignore();
		
		for (int i = 0; i < N; i++)
		{
			int n;
			cin >> n;
			containers.push_back(empty_queue);
			
			for (int j = 0; j < n; j++)
			{
				int a;cin >> a;
				containers.back().push(a);
				n_cargos++;
			}

		}
		
		int pos = 0;
		
		while (true)
		{
			while (not fork_lift.empty() and (fork_lift.top() == pos + 1 || static_cast<int>(containers[pos].size()) < Q))
			{
				int cargo = fork_lift.top();
				
				if (cargo != pos + 1)
					containers[pos].push(cargo);
					
				else
					n_cargos--;
					
				fork_lift.pop();
				time++;
			}
			
			while (not containers[pos].empty() and static_cast<int>(fork_lift.size()) < S)
			{
				int cargo = containers[pos].front();
				containers[pos].pop();
				fork_lift.push(cargo);
				time++;
			}
			
			if (not n_cargos) break;
			
			pos = (pos + 1) % N;
				
			time += 2;
		}
		
		cout << time << endl;
		
	}
	
	return 0;
}
