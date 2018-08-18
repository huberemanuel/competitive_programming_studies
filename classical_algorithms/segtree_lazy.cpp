#include <bits/stdc++.h>

using namespace std;

const int N = 1e7;  // limit for array size
int _n;  // array size
long t[N<<1];
int h; // tree height
long d[N];  

// Objective function, this is a RMQ, change it for the probem
// Take care with variable sizes
long comp(long a, long b) {
	return min(a, b);
}

void build() {  // build the tree
	h = sizeof(int) * 8 - __builtin_clz(_n);
	for (int i = _n - 1; i > 0; --i) t[i] = comp(t[i<<1], t[i<<1|1]);
}

void apply(int p, int value) {
	t[p] += value;
	if (p < _n) d[p] += value;
}

void build(int p) {
	while (p > 1) p >>= 1, t[p] = comp(t[p<<1], t[p*2+1]) + d[p];
}

void push(long p) {
	for (int s = h; s > 0; --s) {
		int i = p >> s;
		if (d[i] != 0) {
		  apply(i<<1, d[i]);
		  apply(i*2+1, d[i]);
		  d[i] = 0;
		}
	}
}

void inc(int l, int r, long value) {
	l += _n, r += _n;
	int l0 = l, r0 = r;
	for (; l < r; l >>= 1, r >>= 1) {
		if (l&1) apply(l++, value);
		if (r&1) apply(--r, value);
	}
	build(l0);
	build(r0 - 1);
}

long query(int l, int r) {
	l += _n, r += _n;
	push(l);
	push(r - 1);
	long res = -2e9;
	for (; l < r; l >>= 1, r >>= 1) {
		if (l&1) res = comp(res, t[l++]);
		if (r&1) res = comp(t[--r], res);
	}
	return res;
}

int main() {

	int n, q; cin >> n >> q;
	_n = n;
	memset(t, 0l, sizeof(t));
	memset(d, 0l, sizeof(d));
	build();

	while (q--) {
		long a, b, k;
		cin >> a >> b >> k;
		inc(a - 1, b, k);
	}

	cout << query(0, n) << endl;

	return 0;
}
