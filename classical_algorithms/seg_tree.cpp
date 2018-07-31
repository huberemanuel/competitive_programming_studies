#include <bits/stdc++.h>

using namespace std;

const int N = 1e7;  // limit for array size
int n;  // array size
long t[2 * N];
int h = sizeof(int) * 8 - __builtin_clz(n);
long d[N];  

void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) t[i] = max(t[i<<1], t[i<<1|1]);
}

void modify(int l, int r, int value) {
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) t[l++] += value;
    if (r&1) t[--r] += value;
  }
}
void apply(int p, int value) {
  t[p] += value;
  if (p < n) d[p] += value;
}

void build(int p) {
  while (p > 1) p >>= 1, t[p] = max(t[p<<1], t[p<<1|1]) + d[p];
}

void push(long p) {
  for (int s = h; s > 0; --s) {
    int i = p >> s;
    if (d[i] != 0) {
      apply(i<<1, d[i]);
      apply(i<<1|1, d[i]);
      d[i] = 0;
    }
  }
}

void inc(int l, int r, long value) {
  l += n, r += n;
  int l0 = l, r0 = r;
  for (; l < r; l >>= 1, r >>= 1) {
    if (l&1) apply(l++, value);
    if (r&1) apply(--r, value);
  }
  build(l0);
  build(r0 - 1);
}

long query(int l, int r) {
  l += n, r += n;
  for (int i = 0; i < n; ++i) cout << d[i] << "\t";
	cout << endl << endl;
  for (int i = 0; i < 2 * n; ++i) cout << t[i] << "\t";
	cout << endl << endl;
  push(l);
  for (int i = 0; i < 2 * n; ++i) cout << t[i] << "\t";
	cout << endl << endl;
  push(r - 1);
  for (int i = 0; i < 2 * n; ++i) cout << t[i] << "\t";
	cout << endl << endl;
  long res = -2e9;
  for (; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = max(res, t[l++]);
    if (r&1) res = max(t[--r], res);
  }
  return res;
}

int main()
{
	n = 4;
	h = sizeof(int) * 8 - __builtin_clz(n);
	cout << h << endl;
	inc(0, n, 1);
	query(0, n);
	//~ vector<vector<int>> queries;
	//~ vector<int> v = {1, 2, 100};
	//~ queries.push_back(v);
	//~ v = {2, 5, 100};
	//~ queries.push_back(v);
	//~ v = {3, 4, 100};
	//~ queries.push_back(v);
	memset(t, 0l, sizeof(t));
    memset(d, 0l, sizeof(d));
	build();
	
	//~ for (auto query : queries)
    //~ {
        //~ long a = query[0], b = query[1], k = query[2];
        //~ inc(a - 1, b, k);
        //~ for (int i = 0; i < 2 * n; ++i) cout << t[i] << "\t";
        //~ cout << endl << endl;
    //~ }
    
	//~ for (int i = 0; i < 2 * n; ++i) cout << t[i] << "\t";
	//~ cout << endl << endl;
	//~ cout << query(0, n + 1);
		
	return 0;
}
