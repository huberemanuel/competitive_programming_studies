#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>

const int neutral = 0;
int comp(int a, int b) {
	return max(a, b); // modificar com o que o problema pedir
}

class SegmentTree {

	private: 
		vi st;
		int size;
		bool maxi;
	public:
		SegmentTree(int *items, int *end) {
			size = (int) (end - items);
			st.assign(size << 1, neutral);
			for (int i = size; i < (size<<1);++i) st[i] = items[i-size];
			for (int i = size - 1;i > 0;--i) st[i] = comp(st[i<<1], st[i<<1|1]);
		}
		int query(int l, int r) {
			int ans = -1e7;
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

	int n;

	while (scanf("%d", &n) != EOF) {

		int items[n], items2[n];
		for (int i = 0;i < n; ++i) scanf("%d", &items[i]), items2[i] = -items[i];

		SegmentTree st1(items, items + n);
		SegmentTree st2(items2, items2 + n);

		int q; scanf("%d", &q);

		while (q--) {
			int op, a, b;
			scanf("%d %d %d", &op, &a, &b);
			if (op & 1) {
				st1.update(a-1, b);
				st2.update(a-1, -b);
			}
			else {
				cout << abs(st1.query(a-1, b) - -st2.query(a-1, b)) << endl;
			}
		}
		
	}

	return 0;
}
