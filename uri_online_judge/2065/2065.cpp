#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, m;
	int v[(int) 10e4], ans = 0;
	
	cin >> n >> m;
	
	for (int i = 0; i < n; ++i) cin >> v[i];
	
	priority_queue< pair<int, int> > pq;
	
	for (int i = 0; i < n; ++i) pq.push( make_pair( 0, -i ) );
	
	for (int i = 0; i < m; ++i)
	{
		int prods;
		cin >> prods;
		
		int id = -pq.top().second;
		int time = -pq.top().first;
		pq.pop();
		pq.push( make_pair(-(time + v[id] * prods), -id ) );
		ans = max(ans, time + v[id] * prods);
	}
	
	cout << ans << endl;
	
	return 0;	
}
