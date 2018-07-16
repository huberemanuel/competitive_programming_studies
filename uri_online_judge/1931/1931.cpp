#include <bits/stdc++.h>

#define pi pair<int, int>
#define vi vector<int>
#define INFINITO 10000000

using namespace std;

int dijkstra(vector< pi > list[], int from, int to, int n_nos)
{
	priority_queue< pi, vector< pi >, greater< pi > > pq;
	vector<bool> visiteds (n_nos, false);
	vi dist (n_nos, INFINITO);

	dist[from] = 0;
	pq.push(make_pair(dist[from], from));

	while (not pq.empty())
	{
		auto actual = pq.top();
		pq.pop();

		if (not visiteds[actual.second])
		{
			visiteds[actual.second] = true;

			for (auto neigh : list[actual.second])
			{
				if (dist[neigh.first] > actual.first + neigh.second)
				{
					pq.push(make_pair(actual.first + neigh.second, neigh.first));
					dist[neigh.first] = actual.first + neigh.second;
				}
			}
		}

	}

	//for (auto i : dist)
	//	cout << i << "\t";
	//cout << endl;

	return (dist[to] == INFINITO ? -1 : dist[to]);
}

int main()
{
	int C, V;

	cin >> C >> V;

	vector< pi > list[C];

	for (int i = 0; i < V; ++i)
	{
		int from, to, w;
		cin >> from >> to >> w;
		list[from - 1].push_back(make_pair(to - 1, w));
		list[to - 1].push_back(make_pair(from - 1, w));
	}

	vector< pi > aux[C];

	for (int i = 0; i < C; ++i)
	{
		for (auto neigh : list[i])
		{
			int vertice = neigh.first;
			int weight = neigh.second;

			for (auto n_neigh : list[vertice])
			{
				int n_vertice = n_neigh.first;
				int n_weight = n_neigh.second;
				aux[i].push_back(make_pair(n_vertice, weight + n_weight));
				//printf("De nó: %d para %d com peso %d\n", i, n_vertice, weight + n_weight);
			}
		}
	}

	cout << dijkstra(aux, 0, C - 1, V) << endl;

	return 0;
}
