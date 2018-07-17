#include <bits/stdc++.h>

using namespace std;

class UnionFind
{
  private:
    vector<int> parent, rank;
  public:
    UnionFind(int N) {
      rank.assign(N + 1, 0);
      parent.assign(N + 1, 0);
      for (int i = 0;i <= N; ++i) parent[i] = i;
    }
    int find(int i){
      while (i != parent[i]) i = parent[i];
      return i;
    }
    bool isSameSet(int i, int j) {
      return find(i) == find(j);
    }
    void unionSet(int i, int j) {
      if (isSameSet(i, j)) return;
      int x = find(i), y = find(j);
      if (rank[x] > rank[y]) parent[y] = x;
      else {
        parent[x] = y;
        if (rank[x] == rank[y]) rank[y]++;
      }
    }
};

typedef pair<int, int> ii;
typedef long long ll;

int N, M;
vector< pair<ll, ii> > edgeList;

ll kruskal() {
  ll cost = 0;
  UnionFind UF(N);

  pair<int, ii> edge;
  sort (edgeList.begin(), edgeList.end());
  for (int i = 0; i < M; ++i) {
    edge = edgeList[i];
    if (!UF.isSameSet(edge.second.first, edge.second.second)) {
      cost += edge.first;
      UF.unionSet(edge.second.first, edge.second.second);
    }
  }
  return cost;
}

int main() {
  
  N = 4;
  M = 5;
  edgeList.push_back(make_pair(10, make_pair(0, 1)));
  edgeList.push_back(make_pair(9, make_pair(1, 2)));
  edgeList.push_back(make_pair(8, make_pair(2, 3)));
  edgeList.push_back(make_pair(7, make_pair(3, 1)));
  edgeList.push_back(make_pair(1, make_pair(0, 3)));
  
  cout << kruskal() << endl;

  return 0;
}
