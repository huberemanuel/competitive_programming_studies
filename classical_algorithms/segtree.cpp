#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>

const int neutral = 0;
int comp(int a, int b) {
	return a + b; // modificar com o que o problema pedir
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
		int query(int l, int r) {
			int ans = neutral;
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

	return 0;
}
