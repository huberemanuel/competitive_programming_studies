#include <bits/stdc++.h>

#define MAX (int) 1e4
#define UNVISITED 0
#define VISITED 2
#define ii pair<int, int>

using namespace std;

struct Tower
{
	int id, enemies, allies, rank = 0;
	bool operator()(const Tower a, const Tower b) {
		if (a.enemies == b.enemies)
			return a.allies < b.allies;
		else
			return a.enemies > b.enemies;
	}
};

int main()
{
	int N, M, S;

	while (cin >> N >> M >> S, !(N == 0 && M == 0 && S == 0))
	{
		int visiteds[N];
		vector<int> list[N];
		Tower towers[N];

		memset(visiteds, UNVISITED, sizeof(visiteds));
		for (int i = 0; i < N; ++i) {towers[i].id = i; cin >> towers[i].enemies;};
		for (int i = 0; i < N; ++i) cin >> towers[i].allies;
		for (int i = 0; i < M; ++i) { int a, b; cin>>a>>b; list[a-1].push_back(b-1); towers[b-1].rank++;}

		priority_queue<Tower, vector<Tower>, Tower> pq;
		for (int i = 0;i < N; ++i) {if (towers[i].rank == 0) pq.push(towers[i]);}
		int count = N;

		while (!pq.empty())
		{
			Tower atual = pq.top(); pq.pop();
			if (visiteds[atual.id]) continue;
			visiteds[atual.id] = VISITED;

			if (atual.enemies >= S)
				break;
			
			S += atual.allies;
			count--;

			for (int neigh : list[atual.id])
				if (--towers[neigh].rank == 0)
					pq.push(towers[neigh]);
		}

		if (!count) cout << "possivel" << endl;
		else cout << "impossivel" << endl;
	}
	return 0;
}
