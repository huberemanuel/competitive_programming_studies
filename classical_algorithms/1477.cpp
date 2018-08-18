#include <bits/stdc++.h>

using namespace std;

#define ll long long

struct Player {
	ll man, elephant, rat;
	bool empty = false;
};

#define vp vector<Player>
#define vb vector<bool>

Player comp(Player a, Player b) {
	a.man += b.man;
	a.elephant += b.elephant;
	a.rat += b.rat;
	return a; 
}

class SegmentTree {

	private: 
		vp st;
		vb lazy;
		int size, h;
		void apply(int p, Player value) {
			st[p] = comp(st[p], value);
			if (p < size) lazy[p] = comp(lazy[p], value);
		}
		void build(int p) {
			while (p) p>>=1, st[p] = comp(comp(st[p<<1], st[p<<1|1]), lazy[p]);
		}
		void push(int p) {
			for (int s = h; s; --s) {
				int i = p >> s;
				if (lazy[i]) {
					apply(i<<1, lazy[i]);
					apply(i<<1|1, lazy[i]);
					st[i] = comp(st[i<<1], st[i<<1|1]);
					lazy[i] = false;
				}
			}
		}
	public:
		SegmentTree(vp items) {
			size = (int) (items.size());
			h = sizeof(int) * 8 - __builtin_clz(size);
			Player empty;
			empty.empty = true;
			st.assign(size << 1, empty);
			lazy.assign(size, false);
			for (int i = size; i < (size<<1);++i) st[i] = items[i-size];
			for (int i = size - 1;i > 0;--i) st[i] = comp(st[i<<1], st[i<<1|1]);
		}
		Player query(int l, int r) {
			Player ans;
			l += size, r += size;
			push(l);
			push(r - 1);
			build(l);
			build(r - 1);
			//for (int i = 1; i < size*2;++i)
			//	cout << st[i] << "\t";
			//cout << endl;
			for (; l < r; l >>= 1, r >>= 1) {
				if (l & 1) ans = comp(ans, st[l++]);
				if (r & 1) ans = comp(ans, st[--r]);
			}
			return ans;
		}
		void update(int l, int r) {
			l += size, r += size;
			for (; l < r; l >>= 1, r >>= 1) {
				if (l&1) lazy[l++] += k;
				if (r&1) lazy[--r] += k;
			}
		}

};


int main() {

	int n, m;

	while (cin >> n >> m) {
		Player p;
		p.man = 1LL;
		vi3 items (n, p);
		SegmentTree st(items);
		
		while (m--) {
			char op;
			int a, b;
			scanf(" %c %d %d", &op, &a, &b);
			if (op == 'C')
				st.update(a - 1, b);
			else {
				int[3] res = st.query(a - 1, b);
				printf("%d %d %d", res[0], res[1], res[2]);
			}
		}
	}

	return 0;
}
