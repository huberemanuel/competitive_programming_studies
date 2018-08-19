#include <bits/stdc++.h>

using namespace std;

#define MAX (int) 4e5
void comp(int *a, int *b) {
	for (int i = 0;i < 3; ++i) a[i] += b[i];
}

class SegmentTree {
private:
	int st[MAX][3];
	vector<int> lazy;
	int size;
	#define left(p) (p << 1)
	#define right(p) ((p << 1) + 1)
	void build(int p, int l, int r) {
		if (l == r) { memset(st[p], 0, sizeof(st[p])); st[p][0] = 1; return; }
		int m = (l + r) / 2;
		build(left(p), l, m);
		build(right(p), m+1, r);
		memset(st[p], 0, sizeof(st[p]));
		comp(st[p], st[left(p)]);
		comp(st[p], st[right(p)]);
	}
	void push(int p, int l, int r) {
		
		if (lazy[p] == 0) return;

		for (int i = 0;i < lazy[p]; ++i) {
			int aux = st[p][2];
			st[p][2] = st[p][1];
			st[p][1] = st[p][0];
			st[p][0] = aux;
		}
		
		if (l != r) {
			lazy[right(p)] = (lazy[right(p)] + lazy[p]) % 3;
			lazy[left(p)] = (lazy[left(p)] + lazy[p]) % 3;
		}
		
		lazy[p] = 0;
	}
	void update(int p, int l, int r, int a, int b) {
		push(p, l, r);
		if (a > r || b < l) return;
		else if (l >= a && r <= b) {
			lazy[p] = 1; push(p, l, r); return;
		}
		update(left(p), l, (l + r) / 2, a, b);
		update(right(p), (l + r) / 2 + 1, r, a, b);
		memset(st[p], 0, sizeof(st[p]));
		comp(st[p], st[left(p)]);
		comp(st[p], st[right(p)]);
	}
	void query(int p, int l, int r, int a, int b, int *ans) {
		push(p, l, r);
		if (a > r || b < l) return;
		if (l >= a && r <= b) comp(ans, st[p]);
		else {
			int m = (l + r) / 2;
			query(left(p), l, m, a, b, ans);
			query(right(p), m+1, r, a, b, ans);
		}
	}
public:
	SegmentTree(int n) {
		size = n;
		lazy.assign(4 * size, 0);
		build(1, 0, size - 1);
	}
	void query(int a, int b, int *ans) { query(1, 0, size - 1, a, b, ans); }
	void update(int a, int b) { update(1, 0, size - 1, a, b); }
};

int main() {

	int n, q;

	while (cin >> n >> q) {
		
		SegmentTree st(n);

		while (q--) {
			char op; int a, b;
			scanf(" %c %d %d", &op, &a, &b);
			if (op == 'M') {
				st.update(a - 1, b - 1);
			}
			else {
				int ans[3];
				memset(ans, 0, sizeof(ans));
				st.query(a - 1, b - 1, ans);
				printf("%d %d %d\n", ans[0], ans[1], ans[2]);
			}
		}
		cout << endl;
	
	}
	return 0;
}
