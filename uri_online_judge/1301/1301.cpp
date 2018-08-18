#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<ll>

const ll neutral = 1LL;
ll comp(ll a, ll b) {
	if (a == 0 or b == 0) return 0;
	else if (a < 0 and b < 0) return 1;
	else if (min(a, b) < 0) return -1;
	return 1;
}

class SegmentTree {

	private: 
		vi st;
		int size;
	public:
		SegmentTree(int *items, int *end) {
			size = (int) (end - items);
			st.assign(size << 1, neutral);
			for (int i = size; i < (size<<1);++i) st[i] = items[i-size];
			for (int i = size - 1;i > 0;--i) st[i] = comp(st[i<<1], st[i<<1|1]);
		}
		ll query(int l, int r) {
			ll ans = neutral;
			for (l += size, r += size; l < r; l >>= 1, r >>= 1) {
				if (l & 1) ans = comp(ans, st[l++]);
				if (r & 1) ans = comp(ans, st[--r]);
			}
			return ans;
		}
		void update(int i, int k) {
			for (st[i+size]=k, i += size, i >>= 1; i; i>>=1) 
				st[i] = comp(st[i<<1], st[i<<1|1]);
		}

};

int main() {

	int n, q; 
	
	while(cin >> n >> q) {
		
		int items[n];
		for (int i = 0;i < n; ++i) cin >> items[i];
		SegmentTree st(items, items + n);

		while (q--) {
			char op;
			int a, b;
			scanf(" %c %d %d", &op, &a, &b);
			if (op == 'C')
				st.update(a-1, b);
			else {
				ll res = st.query(a-1, b);
				if (res > 0) printf("+");
				else if (res < 0) printf("-");
				else printf("0");
			}
		}

		cout << endl;
	}

	return 0;
}
