#include <bits/stdc++.h>

using namespace std;

#define MAX (int) 2e5
void comp(int *a, int *b) {
	for (int i = 0;i < 9; ++i) a[i] += b[i];
}

int most_frequent(int *arr) {
	int index = 0, value = arr[0];
	for (int i = 1;i < 9; ++i) {
		if (arr[i] >= value) {
			index = i;
			value = arr[i];
		}
	}
	return index;
}

class SegmentTree {
private:
	int st[MAX<<1][9];
	int lazy[MAX<<1];
	int size;
	#define left(p) (p << 1)
	#define right(p) ((p << 1) + 1)
	void build(int p, int l, int r) {
		if (l == r) { memset(st[p], 0, sizeof(st[p])); st[p][1] = 1; return; }
		int m = (l + r) / 2;
		build(left(p), l, m);
		build(right(p), m+1, r);
		memset(st[p], 0, sizeof(st[p]));
		comp(st[p], st[left(p)]);
		comp(st[p], st[right(p)]);
	}
	void push(int p, int l, int r) {
		
		if (lazy[p] == 0) return;

		int aux[9];
		for (int i = 0;i < 9; ++i) aux[i] = st[p][i];
		for (int i = 0;i < 9; ++i) {
			st[p][(lazy[p]+i)%9] = aux[i];
		}
		
		if (l != r) {
			lazy[right(p)] = (lazy[right(p)] + lazy[p]) % 9;
			lazy[left(p)] = (lazy[left(p)] + lazy[p]) % 9;
		}
		
		lazy[p] = 0;
	}
	void update(int p, int l, int r, int a, int b, int k) {
		push(p, l, r);
		if (a > r || b < l) return;
		else if (l >= a && r <= b) {
			lazy[p] = k; push(p, l, r); return;
		}
		update(left(p), l, (l + r) / 2, a, b, k);
		update(right(p), (l + r) / 2 + 1, r, a, b, k);
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
		memset(lazy, 0, sizeof(lazy));
		build(1, 0, size - 1);
	}
	int query(int a, int b, int *ans) { 
		query(1, 0, size - 1, a, b, ans); 
		return most_frequent(ans);
	}
	void update(int a, int b) { 
		int ans[9];
		memset(ans, 0, sizeof(ans));
		query(a, b, ans);
		int note = most_frequent(ans);
		update(1, 0, size - 1, a, b, note); 
	}
};

int main() {

	int n, q; cin >> n >> q;
	
	SegmentTree st(n);

	while (q--) {
		int a, b;
		scanf("%d %d", &a, &b);
		st.update(a, b);
	}
	
	int ans[9];
	for (int i = 0;i < n; ++i) {
		memset(ans, 0, sizeof(ans));
		cout << st.query(i, i, ans) << endl;
	}

	return 0;
}

