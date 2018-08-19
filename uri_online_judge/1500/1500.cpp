#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long

const ull neutral = 0ULL; //comp(x, neutral) = x
ull comp(ull a, ull b) {
	return a + b;
}

class SegmentTree {
private:
	vector<ull> st, lazy;
	int size;
#define left(p) (p << 1)
#define right(p) ((p << 1) + 1)
	void build(int p, int l, int r, ull* A) {
		if (l == r) { st[p] = A[l]; return; }
		int m = (l + r) / 2;
		build(left(p), l, m, A);
		build(right(p), m+1, r, A);
		st[p] = comp(st[left(p)], st[right(p)]);
	}
	void push(int p, int l, int r) {
		st[p] += (r - l + 1)*lazy[p];	//Caso RSQ
		//st[p] += lazy[p]; 		    //Caso RMQ
		if (l != r) {
			lazy[right(p)] += lazy[p];
			lazy[left(p)] += lazy[p];
		}
		lazy[p] = 0;
	}
	void update(int p, int l, int r, int a, int b, ull k) {
		push(p, l, r);
		if (a > r || b < l) return;
		else if (l >= a && r <= b) {
			lazy[p] = k; push(p, l, r); return;
		}
		update(left(p), l, (l + r) / 2, a, b, k);
		update(right(p), (l + r) / 2 + 1, r, a, b, k);
		st[p] = comp(st[left(p)], st[right(p)]);
	}
	ull query(int p, int l, int r, int a, int b) {
		push(p, l, r);
		if (a > r || b < l) return neutral;
		if (l >= a && r <= b) return st[p];
		int m = (l + r) / 2;
		ull p1 = query(left(p), l, m, a, b);
		ull p2 = query(right(p), m+1, r, a, b);
		return comp(p1, p2);
	}
public:
	SegmentTree(ull* items, ull* en) {
		size = (int)(en - items);
		st.assign(4 * size, neutral);
		lazy.assign(4 * size, 0);
		build(1, 0, size - 1, items);
	}
	ull query(int a, int b) { return query(1, 0, size - 1, a, b); }
	void update(int a, int b, ull k) { update(1, 0, size - 1, a, b, k); }
};

int main() {

	int T; cin >> T;

	while (T--) {
		int n, q; cin >> n >> q;
		ull items[n];
		memset(items, 0ULL, sizeof(items));
		SegmentTree st(items, items + n);

		while (q--) {
			int op, a, b; long k;
			cin >> op >> a >> b;
			if (op == 0) {
				cin >> k;
				st.update(a - 1, b - 1, k);
			}
			else
				cout << st.query(a - 1, b - 1) << endl;
		}
	
	}
	return 0;
}
