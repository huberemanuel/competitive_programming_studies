#include <bits/stdc++.h>

using namespace std;

struct Order
{
	int size;
	bool side, processed = false;
};

int main()
{
	int c;
	
	cin >> c;
	
	while (c--)
	{
			
		vector<Order> orders;
		queue<Order*> Q;
	
		int l, m;
		
		cin >> l >> m;
		
		for (int i = 0; i < m; i++)
		{
			int a;
			string b;
			cin >> a >> b;
			struct Order aux;
			aux.size = a;
			aux.side = b == "right";
			orders.push_back(aux);
		}
		
		int processed = 0, travels = 0, carrying = 0;
		bool side = false;
		
		while (true)
		{

			while (not Q.empty())
			{
				auto aux = Q.front();
				Q.pop();
				processed++;
				aux->processed = true;
				carrying -= aux->size;
			}
			
			if (static_cast<int>(orders.size()) == processed) break;

			for (unsigned int i = 0; i < orders.size(); i++)
			{
				if (static_cast<int>(Q.size()) > 0 and 
					orders[i].side == side and 
					not orders[i].processed and 
					orders[i].size + carrying > l * 100)
					break;
				
				if (orders[i].side == side and 
					not orders[i].processed and 
					orders[i].size + carrying <= l * 100)
				{
					carrying += orders[i].size;
					Q.push(&orders[i]);
				}
				
			}
			
			side = not side;
			travels++;
		}
		
		cout << travels << endl;
		
	}
	
	return 0;
}

