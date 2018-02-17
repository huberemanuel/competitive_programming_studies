#include <bits/stdc++.h>

using namespace std;

struct Order
{
	unsigned int time;
	int total = -1;
	bool side;
};

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
	
		unsigned int n, t, m;
		
		cin >> n >> t >> m;
		
		for (unsigned int i = 0; i < m; i++)
		{
			int a;
			string b;
			cin >> a >> b;
			//~ cin.ignore();
			struct Order aux;
			aux.time = a;
			aux.side = b == "right";
			orders.push_back(aux);
		}
		
		unsigned int time = 0, processed = 0;
		bool side = true; // true -> right
		
		while (orders.size() != processed)
		{
			//~ cout << Q.size() << endl;
			while (!Q.empty())
			{
				
				auto aux = Q.back();
				aux->total = time;
				Q.pop();
				processed++;
			}
			
			for (unsigned int i = 0; i < orders.size(); i++)
			{
				//~ cout << orders[i].time << endl;
				//~ cout << orders[i].side << endl;
				//~ cout << orders[i].total << endl;
				//~ cout << time << endl;
				
				if (orders[i].time <= time and orders[i].side == side and orders[i].total == -1 and Q.size() <= n)
				{
					cout << "entrei" << endl;
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
