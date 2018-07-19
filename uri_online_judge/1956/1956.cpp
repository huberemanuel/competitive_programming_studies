#include <bits/stdc++.h>

#define ii pair<int, int>
#define ull unsigned long long

using namespace std;

class UnionFind
{
	private:
		vector<int> parent, rank;
		int length;
	public:
		UnionFind(int n) {
			length = n;
			rank.assign(n, 0);
			parent.assign(n, 0);
			for (int i = 0;i < n; ++i) parent[i] = i;
		}
		int find(int u) {
			while (u != parent[u]) {u = parent[u];}
			return u;
		}
		bool isSameSet(int u, int v) {
			return find(u) == find(v);
		}
		void unionSet(int u, int v) {
			if (isSameSet(u, v)) return;
			int x = find(u), y = find(v);
			if (rank[x] > rank[y]) parent[y] = x;
			else {
				parent[x] = y;
				if (rank[x] == rank[y]) rank[y]++;
			}
		}
		int size() {
			map<int, int> m;
			for (int i = 0; i < length; ++i)
				m[find(i)]++;
			return (int) m.size();
		}
};

vector<bool> visiteds;

pair<int, ull> kruskal(vector<pair<int, ii>> edgeList)
{
	ull cost = 0;

	UnionFind UF((int) visiteds.size());
	sort(edgeList.begin(), edgeList.end());
	for (auto item : edgeList)
	{
		if (!UF.isSameSet(item.second.first, item.second.second)) {
			cost += item.first;
			UF.unionSet(item.second.first, item.second.second);
			visiteds[item.second.first] = true;
			visiteds[item.second.second] = true;
		}
	}

	return make_pair(UF.size(), cost);
}

int main()
{
	int n;

	cin >> n;

	vector<pair<int, ii>> edgeList;
	visiteds.assign(n, false);

	for (int i = 0;i < n; ++i)
	{
		int k; cin >> k;
		for (int j = 0;j < k; ++j) 
		{
			int a, b; cin >> a >> b; 
			edgeList.push_back(make_pair(b, make_pair(i, a-1)));
		}
	}

	auto result = kruskal(edgeList);

	cout << result.first << " " << result.second << endl;

	return 0;
}
