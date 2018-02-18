#include <bits/stdc++.h>

using namespace std;

struct Order
{
	int time;
	int total = -1;
	bool side;
};

int find_min_time(vector<Order> orders)
{
	int min_time = 1000000;
	for (int i = 0; i < static_cast<int>(orders.size()); i++)
	{
		if (orders[i].total == -1 and orders[i].time < min_time)
		{
			min_time = orders[i].time;
		}
	}
	if (min_time == 1000000) min_time = 0;
	return min_time;
}

int main()
{
	int c;
	
	cin >> c;
	
	for (int ci = 0; ci < c; ci++)
	{
		
		if (ci > 0)
			cout << endl;
			
		vector<Order> orders;
		queue<Order*> Q;
	
		int n, t, m;
		
		cin >> n >> t >> m;
		
		for (int i = 0; i < m; i++)
		{
			int a;
			string b;
			cin >> a >> b;
			struct Order aux;
			aux.time = a;
			aux.side = b == "right";
			orders.push_back(aux);
		}
		
		int time = 0, processed = 0;
		bool side = false;
		
		while (true)
		{

			while (not Q.empty())
			{
				auto aux = Q.front();
				aux->total = time;
				Q.pop();
				processed++;
			}
			
			if (static_cast<int>(orders.size()) == processed) break;
			
			time = max(time, find_min_time(orders));

			for (unsigned int i = 0; i < orders.size(); i++)
			{
				
				if (orders[i].time <= time and 
					orders[i].side == side and 
					orders[i].total == -1 and 
					static_cast<int>(Q.size()) < n)
				{
					
					Q.push(&orders[i]);
				}
			}
			
			time += t;
			side = not side;
		}
		
		for (unsigned int i = 0; i < orders.size(); i++)
			cout << orders[i].total << endl;
		
	}
	
	return 0;
}
