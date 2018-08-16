#include <bits/stdc++.h>

using namespace std;

#define vll vector<long long>
#define ll long long

const ll neutral = 0LL;
ll comp(ll a, ll b) {
	return a | b; // modificar com o que o problema pedir
}

class SegmentTree {

	private: 
		vll st;
		int size;
	public:
		SegmentTree(ll *items, ll *end) {
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
			return __builtin_popcountll(ans);
		}
		void update(int i, int k) {
			for (st[i+size]=1LL<<k, i += size, i >>= 1; i; i>>=1) 
				st[i] = comp(st[i<<1], st[i<<1|1]);
		}

};


int main() {

	int n, q, m, aux;
	cin >> n >> q >> m;
	ll v[n];
	for (int i = 0;i < n; ++i) cin >> v[i], v[i] = 1LL << v[i];

	SegmentTree st(v, v + n);

	while (q--) {
		int op, a, b; cin >> op >> a >> b;
		if (op & 1) cout << st.query(a - 1, b) << endl;
		else st.update(a - 1, b);
	}

	return 0;
}
