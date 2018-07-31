#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;
int n;
int h = sizeof(int) * 8 - __builtin_clz(n);

struct Node {
	int freq[9];
	Node() {
		memset(freq, 0, sizeof(freq));
	}
	int getFreq() {
		return max_element(freq, freq + 9) - freq;
	}
};

Node t[N<<1];
int lazy[N<<1];

Node merge(Node a, Node b) {
	Node c;
	for (int i = 0; i < 9; ++i) c.freq[i] = a.freq[i] + b.freq[i];
	return c;
}

void build() {
	for (int i = 2*n; i >= n; --i) t[i].freq[1] = 1;
	for (int i = n - 1; i; --i) t[i] = merge(t[i<<1], t[i<<1|1]);

}

int main()
{
	int q; cin >> n >> q;
	h = sizeof(int) * 8 - __builtin_clz(n);
	build();

	for (int i = 0;i < 9; ++i) cout << t[1].freq[i] << "\t";
	cout << endl << endl;
	for (int i = 0;i < 2 * n; ++i) cout << t[i].getFreq() << "\t";

	for (int i = 0; i < q; ++i) {
		int a, b; cin >> a >> b;
		//update();
	}

	//for (int i = n; i < 2 * n; ++i)
	//	cout << max_element(t[i], t[i] + 10) << endl;

	return 0;
}
